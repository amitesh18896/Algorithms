class Float(object):

    def __init__(self,nn,dd=0):
        if dd==0:
            nn,dd = float(nn).as_integer_ratio()
        self.num = nn
        self.den = dd

    def __add__(self,other):
        num = self.num*other.den + self.den*other.num
        den = self.den*other.den
        return self.__class__(num,den)

    def __sub__(self,other):
        num = self.num*other.den - self.den*other.num
        den = self.den*other.den
        return self.__class__(num,den)

    def __mul__(self,other):
        num = self.num*other.num
        den = self.den*other.den
        return self.__class__(num,den)

    def __div__(self,other):
        num = self.num*other.den
        den = self.den*other.num
        return self.__class__(num,den)

    def __mod__(self,num):
        inv = pow(self.den,num-2,num)
        return (self.num*inv)%num

    def __cmp__(self,other):
        lhs = self.num*other.den
        rhs = self.den*other.num
        if lhs==rhs: return 0
        elif lhs<rhs: return -1
        else: return 1

    def __str__(self):
        return '%d/%d'%(self.num,self.den)

    def __float__(self):    # Try to modify for high precision
        return 1.0*self.num/self.den
