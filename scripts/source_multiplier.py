#!/usr/bin/env python3

import sys

def generate_test_file(input_file, n):
    with open(input_file, 'r') as file:
        source_code = file.read()
    
    header_start = source_code.find('__HEADER_BEGIN__') + len('__HEADER_BEGIN__')
    header_end = source_code.find('__HEADER_END__') + len('__HEADER_END__')
    footer_start = source_code.find('__FOOTER_BEGIN__') + len('__FOOTER_BEGIN__')
    footer_end = source_code.find('__FOOTER_END__') + len('__FOOTER_END__')

    header = source_code[header_start:header_end]
    body = source_code[header_end:footer_start]
    footer = source_code[footer_start:footer_end]

    # Generate the multiplied center section
    multiplied_body = ''
    for i in range(n):
        replaced_body = body.replace('__NNNN__', f'{i+1:04d}')
        multiplied_body += replaced_body

    result_code = f'{header}{multiplied_body}{footer}'

    # Remove unecessary tags (FOR SOME REASON DOESN'T WORK?)
    result_code = result_code.replace('__HEADER_BEGIN__', '')
    result_code = result_code.replace('__HEADER_END__', '')
    result_code = result_code.replace('__FOOTER_BEGIN__', '')
    result_code = result_code.replace('__FOOTER_END__', '')

    # Replace __NNNN__ in footer to some real value
    result_code = result_code.replace('__NNNN__', f'{1:04d}')

    # Save the result to "test.cpp"
    with open('test.cpp', 'w') as result_file:
        result_file.write(result_code)


# start program
if len(sys.argv) != 3:
    script_name = sys.argv[0]
    print(f"Usage: {script_name} input_file N")
    sys.exit(1)

input_file = sys.argv[1]
n = int(sys.argv[2])

generate_test_file(input_file, n)
print(f"File 'test.cpp' generated with {n} repetitions.")
