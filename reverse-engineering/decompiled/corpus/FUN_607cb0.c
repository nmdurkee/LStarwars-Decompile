/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x607cb0; label: FUN_00607cb0
 */

void FUN_00607cb0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x10) + 0x3c);
  *(uint *)(*piVar1 + 0x74) = *(uint *)(*piVar1 + 0x74) | 2;
  uVar4 = piVar1[1];
  pbVar3 = (byte *)(((int)(uVar4 + ((int)uVar4 >> 0x1f & 7U)) >> 3) +
                   *(int *)(*piVar1 + 0x58 + (*(uint *)(*piVar1 + 0x74) >> 0xf & 1) * 4));
  uVar4 = uVar4 & 0x80000007;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
  }
  *pbVar3 = *pbVar3 | '\x01' << ((byte)uVar4 & 0x1f);
  FUN_00607590(piVar1,&DAT_009868a0);
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar2 = DAT_009736e0;
  *(uint *)(piVar1[5] + 4) = *DAT_009736e0;
  piVar1[9] = *puVar2;
  *puVar2 = *puVar2 + 0x10;
  *(undefined1 *)*puVar2 = 0x8d;
  *(undefined1 *)(*puVar2 + 1) = 1;
  *(int *)(*puVar2 + 4) = piVar1[6] + 0x10;
  piVar1[5] = *puVar2;
  *puVar2 = *puVar2 + 0x10;
  *(undefined1 *)piVar1[9] = 0xa7;
  *(undefined1 *)(piVar1[9] + 1) = 3;
  *(int *)(piVar1[9] + 4) = param_1;
  piVar1[9] = piVar1[9] + 0x10;
  return;
}

