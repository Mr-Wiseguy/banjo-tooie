# Assembly Macros
.set noat
.set noreorder
.set gp=64
.set fp=64

.macro glabel label
    .global \label
    .ent \label
    \label:
.endm

.macro jlabel label
    .global \label
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro endlabel label
    .end \label
.endm
