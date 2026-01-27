programming_languages = ('php','java','python','c++','c')


# • Use map and lambda to convert these programming languages to upper case in a single
# line of code using map and lambda. Print out the tuple to confirm correct operation.


programming_languages_upper=list(map(lambda lang:lang.upper(), programming_languages))
print(list(zip(programming_languages,programming_languages_upper)))


# • Now rewrite this to use a list comprehension.
programming_languages_upper = [ lang.upper() for lang in programming_languages]

print(list(zip(programming_languages,programming_languages_upper)))


# • Now re-write this to use traditional code i.e. loop and list.


programming_languages_upper=[]

for lang in programming_languages:
    programming_languages_upper.append(lang.upper())




# Without using lambdas
# def starts_with_A(s):
#     return s[0] == "A"


fruits = ["Apple", "Banana", "Pear", "Apricot", "Orange"]
# map_object = map(starts_with_A, fruit)
# print(list(map_object))

print([fruit[0]== 'A' for fruit in fruits])


# Question 3 (examines understanding of map/lambda, general programming constructs and list
# comprehensions):
# a. Ensure that you could clearly explain what the below function is doing, including what each of
# the parameters mean (and their type) and what the output of the function will be. Type this and
# review it with a demonstrator or myself. You should be clear on exactly what is occurring.
zipWith = map(lambda n1, n2: n1 - n2, [7,8,9], [3,2,1])
print(zipWith)
print(list(zipWith))




# b. Write an iterative (traditional) version of ZipWith that returns a list with the results. Show the
# function invocation.

def zipWith(l1,l2):
    l=[]
    for i in range(len(l1)):
        l.append(l1[i]-l2[i])
    return l

print(zipWith([7,8,9], [3,2,1]))


# c. Rewrite the below so as to not use a list comprehension, clearly showing the program output.
# summation = [n for n in range (17) if n > 10]
# print(summation)


summation=[]
for i in range(17):
    if i>10:
        summation.append(i)


print(summation)

# Question 4:
# A city planning function is carefully monitoring the number of high rise buildings being granted
# planning. The building landscape is shown as a 2D list i.e. matrix, with 1’s representing the floors of a
# building. In the example provided below, the tallest building has a height of 4 floors (second last
# column).

# The planning section needs to find out which buildings get sun. Write and invoke a function
# determineElevations(). This function accepts the list of building heights from Part A and
# outputs the number of buildings that get sun. Example:
# determineElevations ([1,2,3,2,4,1]) returns 4 (as 1 is the first element it gets sun. 2 is
# higher so can also see sun. 3 is higher so can see sun. 2 is smaller than 3 so can’t get sun. 4 can get sun. 1 can’t).
# determineElevations ([7,4,8,2,9]) returns 3.


def determineElevations(bl):
    gets_sun=0
    max_lev=0
    for b in range(len(bl[0])):
        lev_num=0
        for l in bl:
            lev_num += l[b]

        if lev_num>max_lev:
            gets_sun+=1
            max_lev=lev_num

    return gets_sun

# buildings_levels=[[0, 0, 0, 0, 0, 0],
#                 [0, 0, 0, 0, 1, 0],
#                 [0, 0, 1, 0, 1, 0],
#                 [0, 1, 1, 1, 1, 0],
#                 [1, 1, 1, 1, 1, 1]]

buildings_levels=[[0, 0, 0, 0, 1],
                [0, 0, 1, 0, 1],
                [1, 0, 1, 0, 1],
                [1, 0, 1, 0, 1],
                [1, 0, 1, 1, 1],
                [1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1]]

print(determineElevations(buildings_levels))



# Question 5:
# Rewrite the below code to solve the same task using:
# a) A while loop rather than a for loop.
# b) A list comprehension.
lst_a = [1, 2, 3, 4, 5]
lst_b = []
# for i in lst_a:
#     lst_b.append(i**2)
# print(lst_b)

#a
i=0
while(i!=len(lst_a)):
    lst_b.append(lst_a[i]**2)
    i+=1

print(lst_b)

#b

lst_b=[num**2 for num in lst_a]
print(lst_b)