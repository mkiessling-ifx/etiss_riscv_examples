import configparser
import sys

def set_value_in_property_file(file_path, section, key, value):
    config = configparser.RawConfigParser()
    config.read(file_path)
    if not config.has_section(section):
        config.add_section(section)
    config[section][key]=value
    cfgfile = open(file_path,'w')
    config.write(cfgfile, space_around_delimiters=False)  # use flag in case case you need to avoid white space.
    cfgfile.close()

if __name__ == "__main__":
    # print(f"Arguments count: {len(sys.argv)}")
    # for i, arg in enumerate(sys.argv):
    #    print(f"Argument {i:>6}: {arg}")
    if not len(sys.argv) == 5:
        print("argument count does not match 4")
        # TODO print usage....
        exit(1)
    
    set_value_in_property_file(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
