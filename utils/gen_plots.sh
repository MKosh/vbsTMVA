#!/bin/bash

# 	Used to write the .tex file containing all of the plots. Run after new plots get generated.
# Purpose:
#       Reads the contents of the plots/####/ folders and adds an \includegraphics 
#       command and a caption for each plot found

plot_file="docs/plots.tex"

if [ -f $plot_file ]; then rm -f $plot_file; fi
touch $plot_file

cat > $plot_file << EOF
\documentclass{article}
\usepackage[margin=0.4in, letterpaper]{geometry}
\usepackage{hyperref}
\usepackage{graphicx}
\usepackage{float}

\begin{document}
    \graphicspath{ {../plots/} }
    \listoffigures
EOF

Cuts=()
Years=()
Canvases=()

for files in plots/*/*.pdf; do 
    cut=$(echo $files | sed 's|^.*\([0-9]\{4\}_\)||g' | sed 's|.pdf||g')
    year=$(echo $files | sed 's|^.*\(c[1-3]_\)||g' | sed "s|_$cut.pdf||g")
    canvas=$(echo $files | sed 's|^.*\([0-9]\{4\}/\)||g' | sed "s|_$year\_$cut.pdf||g")

    if [[ ! "${Years[@]}" =~ "$year" ]]; then
        Years+=("$year")
    fi
    if [[ ! "${Cuts[@]}" =~ "$cut" ]]; then
        Cuts+=("$cut")
    fi
    if [[ ! "${Canvases[@]}" =~ "$canvas" ]]; then
        Canvases+=("$canvas")
    fi
done

for yrs in ${Years[@]}; do
    echo "    \section*{$yrs}" >> $plot_file
    for cts in ${Cuts[@]}; do
    echo "      \subsection*{$cts}" >> $plot_file
        for cvs in ${Canvases[@]}; do
            cat >> $plot_file <<- EOF
            \begin{figure}[H]
                \centering
                \caption{${yrs} plot of ${cvs} variables using cut: \`\`$cts"}
                \includegraphics[width=\textwidth]{$yrs/${cvs}_${yrs}_$cts.pdf}
            \end{figure}
EOF
        done
    done
done
echo "\end{document}" >> $plot_file
    

