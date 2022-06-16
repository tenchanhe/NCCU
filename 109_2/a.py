import random

#size_of_nums1 = random.randint(5, 15)
size_of_nums1 = 30
print(size_of_nums1)
nums1 = [random.randint(-30, 30) for _ in range(size_of_nums1)]
nums1.sort()
nums1 = [str(num) for num in nums1]
print(' '.join(nums1))
#size_of_nums2 = random.randint(5, 15)
size_of_nums2 = 30
print(size_of_nums2)
nums2 = [random.randint(-30, 30) for _ in range(size_of_nums2)]
nums2.sort()
nums2 = [str(num) for num in nums2]
print(' '.join(nums2))

#num_of_case = random.randint(5, 15)
num_of_case = 10
print(num_of_case)
for i in range(num_of_case):
    range1 = [random.randint(0, len(nums1)), random.randint(0, len(nums1))]
    range1.sort()
    range2 = [random.randint(0, len(nums2)), random.randint(0, len(nums2))]
    range2.sort()
    print(range1[0], range1[1], range2[0], range2[1])
