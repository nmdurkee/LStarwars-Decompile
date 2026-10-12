/* Ghidra pseudocode, not original source.
 * ev_8263a5d3e8c49c8909e3cfceaf1282da1bb42b3174c131367c36677ef6ae0531
 * Entry: 0x63bae0; label: FUN_0063bae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0063bae0(void)

{
  int iVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float *unaff_ESI;
  byte *pbVar6;
  float local_8;
  
  local_8 = 3.4028235e+38;
  iVar5 = -1;
  pbVar6 = (byte *)(DAT_0291389c + 0xe8);
  pfVar3 = (float *)(DAT_0291389c + 0x4624);
  iVar4 = 2;
  do {
    if (((*(int *)(&DAT_0291350c + (uint)pbVar6[-0x8c] * 4) == 0) &&
        (fVar2 = (pfVar3[2] - unaff_ESI[2]) * (pfVar3[2] - unaff_ESI[2]) +
                 (*pfVar3 - *unaff_ESI) * (*pfVar3 - *unaff_ESI) +
                 (pfVar3[1] - unaff_ESI[1]) * (pfVar3[1] - unaff_ESI[1]),
        fVar2 < pfVar3[-1] * pfVar3[-1])) && (fVar2 < local_8)) {
      iVar5 = iVar4 + -2;
      local_8 = fVar2;
    }
    if (((*(int *)(&DAT_0291350c + (uint)*pbVar6 * 4) == 0) &&
        (fVar2 = (pfVar3[0x15] - unaff_ESI[2]) * (pfVar3[0x15] - unaff_ESI[2]) +
                 (pfVar3[0x13] - *unaff_ESI) * (pfVar3[0x13] - *unaff_ESI) +
                 (pfVar3[0x14] - unaff_ESI[1]) * (pfVar3[0x14] - unaff_ESI[1]),
        fVar2 < pfVar3[0x12] * pfVar3[0x12])) && (fVar2 < local_8)) {
      iVar5 = iVar4 + -1;
      local_8 = fVar2;
    }
    if (((*(int *)(&DAT_0291350c + (uint)pbVar6[0x8c] * 4) == 0) &&
        (fVar2 = (pfVar3[0x28] - unaff_ESI[2]) * (pfVar3[0x28] - unaff_ESI[2]) +
                 (pfVar3[0x26] - *unaff_ESI) * (pfVar3[0x26] - *unaff_ESI) +
                 (pfVar3[0x27] - unaff_ESI[1]) * (pfVar3[0x27] - unaff_ESI[1]),
        fVar2 < pfVar3[0x25] * pfVar3[0x25])) && (fVar2 < local_8)) {
      iVar5 = iVar4;
      local_8 = fVar2;
    }
    if (((*(int *)(&DAT_0291350c + (uint)pbVar6[0x118] * 4) == 0) &&
        (fVar2 = (pfVar3[0x3b] - unaff_ESI[2]) * (pfVar3[0x3b] - unaff_ESI[2]) +
                 (pfVar3[0x39] - *unaff_ESI) * (pfVar3[0x39] - *unaff_ESI) +
                 (pfVar3[0x3a] - unaff_ESI[1]) * (pfVar3[0x3a] - unaff_ESI[1]),
        fVar2 < pfVar3[0x38] * pfVar3[0x38])) && (fVar2 < local_8)) {
      iVar5 = iVar4 + 1;
      local_8 = fVar2;
    }
    iVar1 = iVar4 + 2;
    pbVar6 = pbVar6 + 0x230;
    pfVar3 = pfVar3 + 0x4c;
    iVar4 = iVar4 + 4;
  } while (iVar1 < 0x20);
  if (iVar5 == -1) {
    return 0;
  }
  DAT_0080fe18 = iVar5;
  return iVar5 * 0x4c + 0x4604 + DAT_0291389c;
}

