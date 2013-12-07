'''
This is a I/O template for code jam.
Usually, what you need to do is:
0. copy the content to your code;
1. def a function: read_case(fi) to read what you need from string fi and return it to solver;
2. def a function: solver(case) to retrive the value form read_case(), solve it and return the answer as string;
3. call function solve(solver, inputfile, outputfile) to read input from inputfile.in and output the answer to outputfile
'''
def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
	return int(read_word(f), b)

def read_letters(f):
	return list(read_word(f))

def read_digits(f, b=10):
	return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
	return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
	return [int(x, b) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
	res = []
	for i in range(R):
		res.append(reader(f, *args, **kwargs))
	return res

def solve(solver, fn, out_fn=None):
	in_fn = fn + '.in'
	if out_fn is None:
		out_fn = fn + '.out'
	with open(in_fn, 'r') as fi:
		with open(out_fn, 'w') as fo:
			T = read_int(fi)
			for i in range(T):
				case = read_case(fi)
				res = solver(case)
				write_case(fo, i, res)
				
def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write(res)
    f.write('\n')

################################################################################