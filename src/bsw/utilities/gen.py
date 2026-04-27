import math

LUT_SIZE = 128
PWM_MAX = 22500

lut = []
for i in range(LUT_SIZE):
    val = int((math.sin(2*math.pi*i/LUT_SIZE)*0.5 + 0.5) * PWM_MAX)
    lut.append(val)

print(lut)