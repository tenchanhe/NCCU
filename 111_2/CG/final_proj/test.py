package

{

    import Box2D.Collision.b2AABB;
    import Box2D.Collision.Shapes.b2CircleDef;
    import Box2D.Collision.Shapes.b2PolygonDef;
    import Box2D.Collision.Shapes.b2ShapeDef;
    import Box2D.Common.Math.b2Vec2;
    import Box2D.Dynamics.b2Body;
    import Box2D.Dynamics.b2BodyDef;
    import Box2D.Dynamics.b2DebugDraw;
    import Box2D.Dynamics.b2World;
    import flash.display.Sprite;
    import flash.events.Event;
    import flash.events.MouseEvent;
 
    /**
     * http://www.ladeng6666.com
     * @author ladeng6666
     */
    publicclassMainextendsSprite
    {

        privatevarworld:b2World;

        privatevarbody:b2Body;

 

        publicfunctionMain()

        {

            //创建box2D世界

            createWorld();

            //创建box2D调试图

            createDebug();

            //创建刚体

            createStuff(stage.stageWidth/2,0);

            //创建圆形边界

            createCircleGround();

            //侦听事件

            addEventListener(Event.ENTER_FRAME,loop);

            stage.addEventListener(MouseEvent.MOUSE_DOWN,onStageMouseDown);

        }

 

        privatefunctiononStageMouseDown(e:MouseEvent):void

        {

            //在鼠标位置随机创建一个圆形或矩形刚体

            createStuff(mouseX,mouseY,Math.random()>0.5);

        }

 

        privatefunctionloop(e:Event):void

        {

            world.Step(1/30,10);

        }

 

        privatefunctioncreateWorld():void

        {

            //1.创建一个环境

            varenvironment:b2AABB=newb2AABB();

            environment.lowerBound=newb2Vec2(-100,-100);

            environment.upperBound=newb2Vec2(100,100);

            //2.声明重力

            vargravity:b2Vec2=newb2Vec2(0,10);

            //3.睡着的对象是否模拟

            vardoSleep:Boolean=true;

            //4.创建b2World世界

            world=newb2World(environment,gravity,doSleep);

        }

 

        privatefunctioncreateDebug():void

        {

            vardebugSprite:Sprite=newSprite();

            addChild(debugSprite);

 

            vardebugDraw:b2DebugDraw=newb2DebugDraw();

            debugDraw.m_sprite=debugSprite;

            debugDraw.m_drawScale=30.0;

            debugDraw.m_fillAlpha=0.5;

            debugDraw.m_lineThickness=1.0;

            debugDraw.m_drawFlags=b2DebugDraw.e_shapeBit|b2DebugDraw.e_jointBit;

 

            world.SetDebugDraw(debugDraw);

        }

        privatefunctioncreateStuff(posX:Number,posY:Number,isBox:Boolean=true):void

        {

            //1.创建刚体需求b2BodyDef

            varbodyRequest:b2BodyDef=newb2BodyDef();

            bodyRequest.position.Set(posX/30,posY/30);//记得米和像素的转换关系

            //2.Box2D世界工厂更具需求创建createBody()生产刚体

            body=world.CreateBody(bodyRequest);

            //3.创建敢提形状需求b2ShapeDef的子类

            if(isBox){

                //创建矩形刚体形状需求

                varshapeBoxRequest:b2PolygonDef=newb2PolygonDef();

                shapeBoxRequest.density=3;

                shapeBoxRequest.friction=0.3;

                shapeBoxRequest.restitution=0.2;

                shapeBoxRequest.SetAsBox(1,1);

                body.CreateShape(shapeBoxRequest);

 

            }else{

                //创建圆形刚体形状需求

                varshapeCircleRequest:b2CircleDef=newb2CircleDef();

                shapeCircleRequest.density=3;

                shapeCircleRequest.friction=0.3;

                shapeCircleRequest.restitution=0.2;

                shapeCircleRequest.radius=1;

                body.CreateShape(shapeCircleRequest);

            }

            body.SetMassFromShapes();

        }

 

        privatefunctioncreateCircleGround():void

        {

            varcenterX:Number=stage.stageWidth/2;

            varcenterY:Number=stage.stageHeight/2;

            //1.创建刚体需求b2BodyDef

            varbodyRequest:b2BodyDef=newb2BodyDef();

            bodyRequest.position.Set(centerX/30,centerY/30);//记得米和像素的转换关系

            //2.Box2D世界工厂更具需求创建createBody()生产刚体

            body=world.CreateBody(bodyRequest);

 

            //3.创建敢提形状需求b2ShapeDef的子类

            //定义线段的个数

            varsegmentNum:Number=36;

            //定义圆形边界的半径

            varradius:Number=200;

            //根据半径和个数计算线段的长度

            varsegmentlength:Number=radius *Math.sin(Math.PI/segmentNum);

            //for循环创建segmentNum个线段，合成圆形边界

            for(vari:int=0;i<segmentNum;i++){

                //定义形状需求

                varshapeRequest:b2PolygonDef=newb2PolygonDef();

                //形状的质量、摩擦系数、硬度

                shapeRequest.density=0;

                shapeRequest.friction=0.3;

                shapeRequest.restitution=0.2;

                //计算每个线段的角度、坐标

                varangle:Number=i/segmentNum *Math.PI*2;

                varbx:Number=radius *Math.cos(angle);

                varby:Number=radius *Math.sin(angle);

                //创建有方向的矩形刚体，合成总的圆形刚体

                shapeRequest.SetAsOrientedBox(5/30,segmentlength/30,newb2Vec2(bx/30,by/30),angle);

                //4.b2Body刚体工厂根据需求createShape生产形状

                body.CreateShape(shapeRequest);

            }

 

            body.SetMassFromShapes();

        }

    }

 

}
