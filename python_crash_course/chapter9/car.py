
class Car():
    
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer = 0

    def get_desc_name(self):
        long_name = str(self.year) + " " + self.make + ' ' + self.model
        return long_name.title()

    def read_odometer(self):
        print("This car has " + str(self.odometer) + " miles on it.")

    def update_odometer(self, mileage):
        if mileage > self.odometer:
            self.odometer = mileage
        else:
            print("You can not roll back an odometer!")

    def increment_odometer(self, mileage):
        self.odometer += mileage

class ECar(Car):
    def __init__(self, make, model, year):
        super().__init__(make, model, year)

my_new_car = Car('audi', "a4", 2016)
print(my_new_car.get_desc_name())
my_new_car.read_odometer()

my_new_car.odometer = 100 #直接修改成员变量的值
my_new_car.read_odometer()

my_new_car.update_odometer(23) #使用方法更新成员变量
my_new_car.read_odometer()

my_new_car.update_odometer(105) #使用方法更新成员变量
my_new_car.read_odometer()

my_new_car.increment_odometer(100)  #使用方法对里程表加一个增量
my_new_car.read_odometer()

my_tesla = ECar('tesla', 'model s', 2016)
print(my_tesla.get_desc_name())
