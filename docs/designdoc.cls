%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NAME:             designdoc.cls
%
% AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
%
% DESCRIPTION:      LaTeX class file for design documents.
%
% CREATED:          05/15/2019
%
% LAST EDITED:      08/08/2019
%%%

\LoadClass{article}
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{designdoc}[2019/05/15 Class for Software Design Documents]

\pagestyle{empty} % Prevent style conflicts with `fancy'
\RequirePackage[margin=1in]{geometry} % Pretty much just to set the margins
\RequirePackage{fancyhdr} % Header & Footer
\RequirePackage{setspace} % Spacing.
\RequirePackage{subfiles}
\RequirePackage{pdfpages}
\RequirePackage{graphicx}
\RequirePackage{relsize}
\RequirePackage{algorithm}
\RequirePackage[noend]{algpseudocode}
\RequirePackage{minted}
\RequirePackage{amsmath}
\RequirePackage{hyperref}
\RequirePackage{tabularx}
\RequirePackage{fmtcount}

\hypersetup{
  colorlinks=true,
  linkcolor=blue,
  urlcolor=cyan
}

% Header
\setlength{\headheight}{28pt}
\pagestyle{fancy}
\fancyhf{}
\rhead{Ethan D. Twardy}
\lhead{SortMedia Design Document}
\cfoot{\thepage}

\newcommand{\expnumber}[2]{{#1}\mathrm{e}{#2}}

\setlength{\parskip}{10pt}
\setlength{\parindent}{0pt}

\newcommand{\answer}[1]{
  \begin{enumerate}
  \item[] #1
  \end{enumerate}
}

\newsavebox{\mybox}
\newenvironment{Answer}%
{\par\begin{lrbox}{\mybox}\begin{minipage}{\linewidth-7pt}}
{\end{minipage}\end{lrbox}\fbox{\usebox{\mybox}}}

\newcounter{TheRequirement}
\newcounter{reqpadding}
\setcounter{reqpadding}{4}
\newcommand{\swrequirement}[1]{
  \stepcounter{TheRequirement}
  \subsection*{SR\padzeroes[\value{reqpadding}]{\decimal{TheRequirement}}: #1}
}

\setminted{fontsize=\footnotesize}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
