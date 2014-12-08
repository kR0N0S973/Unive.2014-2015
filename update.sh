#!/bin/bash
git add .
read -p "What did you changed => " edityn
git commit -a -m edityn
git push
