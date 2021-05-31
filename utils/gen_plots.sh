#!/bin/bash

# 	Used to write the .tex file containing all of the plots. Run after new plots get generated.
# Purpose:
#       Reads the contents of the plots/####/ folders and adds an \includegraphics 
#       command and a caption for each plot found

plot_file="docs/plots2.tex"

if [ ! -f $plot_file ]; then touch $plot_file; fi

cat > $plot_file << EOF
\documentclass{article}
\usepackage[margin=1in, letterpaper]{geometry}
\usepackage{graphicx}
\usepackage{float}

\begin{doucment}
    \graphicspath{ {../plots/} }
EOF

Cuts=()
Years=()
Canvases=()

for files in plots/*/*.pdf; do 
    cut=$(echo $files | sed 's|^.*\([0-9]\{4\}_\)||g' | sed 's|.pdf||g')
    year=$(echo $files | sed 's|^.*\(c[1-3]_\)||g' | sed "s|_$cut.pdf||g")
    canvas=$(echo $files | sed 's|^.*\([0-9]\{4\}/\)||g' | sed "s|_$year\_$cut.pdf||g")

    if [[ ! "${Years[@]}" =~ "$year" ]]; then
        ${Years}+=("$year")
    fi
    if [[ ! "${Cuts[@]}" =~ "$cut" ]]; then
        ${Cuts}+=("$cut")
    fi
done

for yrs in ${Years[@]}; do
    echo "  \section*{$yrs}" >> $plot_file
    for cts in ${Cuts[@]}; do
        cat >> $plot_file <<- EOF
                \subsection*{$cts}
                    \begin{figure}[H]
                        \centering
                        \includegraphics{$yrs/c1_$yrs_$cts.pdf}
                        \caption{c1 plot for $yrs using the $cts cut}
                    \end{figure}
                        \begin{figure}[H]
                        \centering
                        \includegraphics{$yrs/c2_$yrs_$cts.pdf}
                        \caption{c2 plot for $yrs using the $cts cut}
                    \end{figure}
                    \begin{figure}[H]
                        \centering
                        \includegraphics{$yrs/c3_$yrs_$cts.pdf}
                        \caption{c3 plot for $yrs using the $cts cut}
                    \end{figure}
EOF
    done
done
    

