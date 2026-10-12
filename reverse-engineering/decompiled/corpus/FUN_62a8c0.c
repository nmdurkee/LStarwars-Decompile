/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a8c0; label: FUN_0062a8c0
 */

void FUN_0062a8c0(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  byte bVar2;
  undefined8 uVar3;
  
  if (param_2 != 0) {
    puVar1 = (uint *)(param_1 + 8 + (uint)*(byte *)(param_2 + 0x28d) * 8);
    uVar3 = __allshl();
    *puVar1 = *puVar1 & ~(uint)uVar3;
    puVar1[1] = puVar1[1] & ~(uint)((ulonglong)uVar3 >> 0x20);
    return;
  }
  bVar2 = *(byte *)(param_3 + 0x28d);
  *(undefined4 *)(param_1 + 8 + (uint)bVar2 * 8) = 0;
  *(undefined4 *)(param_1 + 0xc + (uint)bVar2 * 8) = 0;
  return;
}

