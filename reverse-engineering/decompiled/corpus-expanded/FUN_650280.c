/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650280; label: FUN_00650280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650280(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (DAT_02962044 == 0) {
    DAT_02947d80 = *param_1 + 3U & 0xfffffffc;
    *param_1 = (*param_1 + 3U & 0xfffffffc) + 0x400;
    uVar3 = 0;
    do {
      uVar1 = uVar3 << 0x19;
      if ((int)(uVar3 << 0x18) < 0) {
        uVar1 = uVar1 ^ 0x4c11db7;
      }
      uVar2 = uVar1 * 2;
      if ((int)uVar1 < 0) {
        uVar2 = uVar2 ^ 0x4c11db7;
      }
      uVar1 = uVar2 * 2;
      if ((int)uVar2 < 0) {
        uVar1 = uVar1 ^ 0x4c11db7;
      }
      uVar2 = uVar1 * 2;
      if ((int)uVar1 < 0) {
        uVar2 = uVar2 ^ 0x4c11db7;
      }
      uVar1 = uVar2 * 2;
      if ((int)uVar2 < 0) {
        uVar1 = uVar1 ^ 0x4c11db7;
      }
      uVar2 = uVar1 * 2;
      if ((int)uVar1 < 0) {
        uVar2 = uVar2 ^ 0x4c11db7;
      }
      uVar1 = uVar2 * 2;
      if ((int)uVar2 < 0) {
        uVar1 = uVar1 ^ 0x4c11db7;
      }
      uVar2 = uVar1 * 2;
      if ((int)uVar1 < 0) {
        uVar2 = uVar2 ^ 0x4c11db7;
      }
      *(uint *)(DAT_02947d80 + uVar3 * 4) = uVar2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    DAT_02962044 = 1;
  }
  return;
}

