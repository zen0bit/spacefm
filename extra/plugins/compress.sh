#!/bin/bash

# compress plugins

for f in ${PWD}/*;do
	if [ -d "${f}" ];then
		cd "${f}"
		plugin="$(basename ${f}).tar.xz"
		if [ ! -f "${pligin}" ];then
			tar --numeric-owner -cJf "../${plugin}" *
		fi
	fi
done

