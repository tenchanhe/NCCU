while True:
        try:
                H,W = input().split()
                H = float(H)
                H = H/100
                W = float(W)
                BMI = W/(H**2)
                #print(BMI)

                if BMI <= 18.5:
                        print('underweight')

                elif BMI > 18.5 and BMI <= 25:
                        print('normal weight')

                elif BMI > 25 and BMI <= 30:
                        print('overweight')

                elif BMI > 30:
                        print('obese')

        except:
                exit()
