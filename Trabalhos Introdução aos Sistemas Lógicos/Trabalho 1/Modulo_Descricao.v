module traducao (iW, iX, iY, iZ, oA, oB, oC, oD, oE, oF, oG);
    input iW, iX, iY, iZ;
    output oA, oB, oC, oD, oE, oF, oG;

    wire iW, iX, iY, iZ, oA, oB, oC, oD, oE, oF, oG;

    assign p0 = ~iX & ~iY & ~iZ;
    assign p1 = ~iW;

    assign p2 = ~iW & ~iX & ~iZ;
    assign p3 = ~iW & ~iX & ~iY;
    assign p4 = ~iY & ~iZ;
    assign p5 = iW & iX & ~iZ;
    assign p6 = iW & ~iY;

    assign p7 = ~iY & ~iZ;
    assign p8 = ~iW & iZ;
    assign p9 = iX & iY & iZ;

    assign p10 = iW & iZ;
    assign p11 = iW & ~iX;
    assign p12 = iX & iY & ~iZ;

    assign p13 = iW & ~iX & iY & iZ;
    assign p14 = ~iW & iX & iY;
    assign p15 = iX & iY & ~iZ;

    assign p16 = ~iW & ~iX;
    assign p17 = ~iW & iY & ~iZ;
    assign p18 = iW & ~iY & ~iZ;
    assign p19 = iW & ~iX & iZ;

    assign p20 = iX & ~iY & iZ;
    assign p21 = iW & ~iX & iY;

    assign oA = p0 | p1;
    assign oB = p2 | p3 | p4 | p5 | p6;
    assign oC = p7 | p8 | p9;
    assign oD = p0 | p10 | p11 | p12;
    assign oE = p7 | p13 | p14 | p15;
    assign oF = p16 | p17 | p18 | p19; 
    assign oG = p0 | p20 | p21;

endmodule