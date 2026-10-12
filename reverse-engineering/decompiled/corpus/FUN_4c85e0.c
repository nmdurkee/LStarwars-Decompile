/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c85e0; label: FUN_004c85e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c85e0(undefined4 param_1,float param_2)

{
  byte *pbVar1;
  char cVar2;
  float fVar3;
  int iVar4;
  byte bVar5;
  undefined **ppuVar6;
  float *pfVar7;
  bool bVar8;
  float10 fVar9;
  
  fVar3 = param_2;
  cVar2 = *(char *)((int)param_2 + 0x7b5);
  if (cVar2 != 'L') {
    if (*(char *)((int)param_2 + 0x281) != '\0') {
      return;
    }
    if (cVar2 == '\x1f') {
      return;
    }
    if (cVar2 == '+') {
      return;
    }
    if (cVar2 == 'K') {
      return;
    }
    if ((*(byte *)((int)param_2 + 0x1fc) & 0x80) == 0) {
      return;
    }
    if ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x800) != 0) {
      return;
    }
    iVar4 = FUN_004c7f60(param_1,(int)param_2 + 0x80,param_2,&param_2);
    if (iVar4 == 0) {
      return;
    }
    if (0.0625 <= param_2) {
      return;
    }
    *(undefined4 *)((int)fVar3 + 0x77c) = 0;
    *(undefined1 *)((int)fVar3 + 0x7b5) = 0x4c;
    *(int *)((int)fVar3 + 0x798) = iVar4;
    *(undefined2 *)((int)fVar3 + 0x7aa) = 0x96;
    fVar9 = (float10)FUN_0062e040((int)*(short *)((int)fVar3 + 0x1064),0x96,0,0,1);
    *(float *)((int)fVar3 + 0x784) = (float)fVar9;
    if ((float)fVar9 <= 0.0) {
      *(undefined4 *)((int)fVar3 + 0x784) = 0x3f800000;
    }
    *(uint *)((int)fVar3 + 0x7bc) = *(uint *)((int)fVar3 + 0x7bc) & 0xffffffbf;
    return;
  }
  pfVar7 = (float *)0x0;
  if ((*(int *)(*(int *)(*(int *)((int)param_2 + 0x50) + 0xc) + *(short *)((int)param_2 + 0x7aa) * 4
               ) != 0) &&
     (pfVar7 = (float *)FUN_0062f150((int)param_2 + 8,(int)*(short *)((int)param_2 + 0x7aa),1,0),
     pfVar7 == (float *)0x0)) {
    return;
  }
  param_2 = *(float *)((int)fVar3 + 0x77c) + _DAT_00925018;
  *(float *)((int)fVar3 + 0x77c) = param_2;
  if (*(float *)((int)fVar3 + 0x784) < param_2 == (*(float *)((int)fVar3 + 0x784) == param_2)) {
    bVar8 = false;
    if ((*(byte *)((int)fVar3 + 0x7bc) & 0x40) != 0) goto LAB_004c8788;
    if (pfVar7 != (float *)0x0) {
      fVar9 = (float10)FUN_0062f1f0(*(undefined4 *)((int)fVar3 + 0x50),
                                    (int)*(short *)((int)fVar3 + 0x7aa),0);
      param_2 = (float)fVar9;
      if ((1.0 <= param_2) && (param_2 <= *pfVar7)) goto LAB_004c8678;
    }
  }
  else {
    bVar5 = *(byte *)((int)fVar3 + 0x7bc);
    *(undefined1 *)((int)fVar3 + 0x7b5) = 0xff;
    FUN_00561d20(fVar3);
    if ((bVar5 & 0x40) == 0) {
LAB_004c8678:
      pbVar1 = (byte *)(*(int *)((int)fVar3 + 0x798) + 0x6a);
      *pbVar1 = *pbVar1 | 4;
      *(uint *)((int)fVar3 + 0x7bc) = *(uint *)((int)fVar3 + 0x7bc) | 0x40;
      iVar4 = *(int *)((int)fVar3 + 0xcbc);
      *(uint *)((int)fVar3 + 0x4bc) = *(uint *)((int)fVar3 + 0x4bc) & ~*(uint *)(iVar4 + 0x10);
      *(undefined4 *)((int)fVar3 + 0xcbc) = *(undefined4 *)(*(int *)((int)fVar3 + 0x798) + 0x80);
      *(int *)(*(int *)((int)fVar3 + 0x798) + 0x80) = iVar4;
      *(uint *)((int)fVar3 + 0x4bc) =
           *(uint *)((int)fVar3 + 0x4bc) | (uint)(*(undefined ***)((int)fVar3 + 0xcbc))[4];
      bVar5 = 0;
      ppuVar6 = &PTR_s_batman_007fcfb8;
      iVar4 = 0;
      do {
        if (*(undefined ***)((int)fVar3 + 0xcbc) == ppuVar6) {
          DAT_0087aa8c = DAT_0087aa8c | 1 << (bVar5 & 0x1f);
          break;
        }
        iVar4 = iVar4 + 0x18;
        bVar5 = bVar5 + 1;
        ppuVar6 = ppuVar6 + 6;
      } while (iVar4 < 0xf0);
      FUN_0054a8a0(**(undefined4 **)((int)fVar3 + 0xca4),0x3dcccccd,0);
      FUN_0054a850(**(undefined4 **)((int)fVar3 + 0xca4),0x3f19999a,0);
    }
  }
  bVar8 = (*(byte *)((int)fVar3 + 0x7bc) & 0x40) == 0;
LAB_004c8788:
  if (bVar8) {
    iVar4 = FUN_0054fa60(0);
    param_2 = (float)iVar4 * 1.5259022e-05 * 0.4;
    FUN_0054a850(**(undefined4 **)((int)fVar3 + 0xca4),param_2);
  }
  return;
}

