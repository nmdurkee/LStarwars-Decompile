/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x607ec0; label: FUN_00607ec0
 */

void FUN_00607ec0(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  
  if (param_3 == 0) {
    param_3 = DAT_0095e670;
  }
  DAT_02854c31 = *(short *)(param_3 + 0x74) != 0;
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  piVar6 = *(int **)(param_3 + 0x3c);
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)&DAT_00973e70;
  }
  else {
    *(uint *)(*piVar6 + 0x74) = *(uint *)(*piVar6 + 0x74) | 2;
    uVar5 = piVar6[1];
    pbVar3 = (byte *)(((int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3) +
                     *(int *)(*piVar6 + 0x58 + (*(uint *)(*piVar6 + 0x74) >> 0xf & 1) * 4));
    uVar5 = uVar5 & 0x80000007;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
    }
    *pbVar3 = *pbVar3 | '\x01' << ((byte)uVar5 & 0x1f);
  }
  FUN_00607590(piVar6,&DAT_009868a0);
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar2 = DAT_009736e0;
  *(uint *)(piVar6[5] + 4) = *DAT_009736e0;
  piVar6[9] = *puVar2;
  *puVar2 = *puVar2 + 0x20;
  *(undefined1 *)*puVar2 = 0x8d;
  *(undefined1 *)(*puVar2 + 1) = 1;
  *(int *)(*puVar2 + 4) = piVar6[6] + 0x10;
  piVar6[5] = *puVar2;
  *puVar2 = *puVar2 + 0x10;
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar2 = DAT_009736e0;
  if (param_4 == (undefined *)0x0) {
    param_4 = &DAT_0080e270;
  }
  uVar4 = FUN_00603580(DAT_009736e0,param_4,0,0,0);
  puVar1 = (undefined4 *)*puVar2;
  *puVar2 = (uint)(puVar1 + 0xe);
  *puVar1 = param_1;
  DAT_02854d18 = puVar1 + 6;
  *(undefined1 *)piVar6[9] = 0x8c;
  *(undefined1 *)(piVar6[9] + 1) = 3;
  *(undefined4 *)(piVar6[9] + 4) = uVar4;
  piVar6[9] = piVar6[9] + 0x10;
  *(undefined1 *)piVar6[9] = 0x82;
  *(undefined1 *)(piVar6[9] + 1) = 3;
  *(undefined4 **)(piVar6[9] + 4) = puVar1;
  piVar6[9] = piVar6[9] + 0x10;
  return;
}

