/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x607d70; label: FUN_00607d70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00607d70(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  
  if (param_3 == 0) {
    param_3 = DAT_0096d8f0;
  }
  DAT_02854c31 = *(short *)(param_3 + 0x74) != 0;
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar3 = DAT_009736e0;
  piVar6 = *(int **)(param_3 + 0x3c);
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)&DAT_00973e70;
    FUN_005de2d0(&DAT_00973e70,param_3);
  }
  else {
    *(uint *)(*piVar6 + 0x74) = *(uint *)(*piVar6 + 0x74) | 2;
    uVar5 = piVar6[1] & 0x80000007;
    pbVar1 = (byte *)(*(int *)(*piVar6 + 0x58 + (*(uint *)(*piVar6 + 0x74) >> 0xf & 1) * 4) +
                     ((int)(piVar6[1] + (piVar6[1] >> 0x1f & 7U)) >> 3));
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    *pbVar1 = *pbVar1 | '\x01' << ((byte)uVar5 & 0x1f);
  }
  _DAT_009868c0 = _DAT_009868c0 + 1;
  _DAT_00986998 = 0;
  _DAT_009868be = _DAT_009868be + 1;
  _DAT_0098699c = 0;
  _DAT_00986994 = 0;
  _DAT_00986a20 = 0;
  FUN_00607590(piVar6,&DAT_009868a0);
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar4 = DAT_009736e0;
  *(uint *)(piVar6[5] + 4) = *DAT_009736e0;
  piVar6[9] = *puVar4;
  *puVar4 = *puVar4 + 0x10;
  *(undefined1 *)*puVar4 = 0x8d;
  *(undefined1 *)(*puVar4 + 1) = 1;
  *(int *)(*puVar4 + 4) = piVar6[6] + 0x10;
  piVar6[5] = *puVar4;
  *puVar4 = *puVar4 + 0x10;
  DAT_02854d10 = puVar3;
  puVar2 = (undefined4 *)*puVar3;
  *puVar3 = (uint)(puVar2 + 0xe);
  *puVar2 = param_1;
  DAT_02854d14 = 0;
  DAT_02854d18 = puVar2 + 6;
  *(undefined1 *)piVar6[9] = 0x93;
  DAT_0080e26c = param_1;
  *(undefined1 *)(piVar6[9] + 1) = 3;
  *(undefined4 **)(piVar6[9] + 4) = puVar2;
  piVar6[9] = piVar6[9] + 0x10;
  return;
}

