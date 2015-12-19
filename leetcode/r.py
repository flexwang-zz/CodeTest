import glob
import sys
import os
a = glob.glob('*.cpp')
for s in a:
    s0 = s.lower()
    print(s0)
    os.rename(s, s0)
