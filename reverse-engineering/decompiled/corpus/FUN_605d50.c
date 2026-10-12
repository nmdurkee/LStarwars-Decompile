/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x605d50; label: FUN_00605d50
 */

void FUN_00605d50(void)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  undefined1 auStack_4 [4];
  
  if (DAT_02854c08 != (int *)0x0) {
    (**(code **)(*DAT_02854c08 + 8))(DAT_02854c08);
    DAT_02854c08 = (int *)0x0;
  }
  if (DAT_02854c0c != (int *)0x0) {
    (**(code **)(*DAT_02854c0c + 8))(DAT_02854c0c);
    DAT_02854c0c = (int *)0x0;
  }
  FUN_006e5b70(&DAT_02854c08);
  FUN_006e4810(0x40000,0x208,0,0,&DAT_02854c08);
  FUN_005f99d0();
  FUN_006e46f0(0xc000,0,0x65,1,&DAT_02854c0c,0);
  psVar3 = (short *)0x0;
  iVar1 = (**(code **)(*DAT_02854c0c + 0x2c))(DAT_02854c0c,0,0,auStack_4,0);
  if (-1 < iVar1) {
    sVar2 = 0;
    iVar1 = 0x1000;
    do {
      *psVar3 = sVar2;
      psVar3[1] = sVar2 + 1;
      psVar3[2] = sVar2 + 2;
      psVar3[3] = sVar2;
      psVar3[4] = sVar2 + 2;
      psVar3[5] = sVar2 + 3;
      psVar3 = psVar3 + 6;
      sVar2 = sVar2 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    (**(code **)(*DAT_02854c0c + 0x30))(DAT_02854c0c);
  }
  return;
}

