#!/usr/bin/env python3

def add_custom_arguments(parser):
    group = parser.add_mutually_exclusive_group(required=False)
    group.add_argument('-u', dest='ver', action='store_const', const='us',
            help="Set version to us.")

def apply(config, args):
    ver = args.ver or 'us'
    config['mapfile'] = f'build/{ver}/banjotooie_decompressed.map'
    config['myimg'] = f'build/{ver}/banjotooie_decompressed.z64'
    config['baseimg'] = f'decompressed.{ver}.z64'
    config['makeflags'] = [f'VERSION={ver}']
    config['source_directories'] = ['src', 'include']
