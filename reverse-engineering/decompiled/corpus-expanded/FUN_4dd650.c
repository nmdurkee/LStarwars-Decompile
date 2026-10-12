/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd650; label: FUN_004dd650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dd650(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  FUN_004dd3b0(param_1);
  DAT_0087aa20 = 0;
  iVar2 = 0;
  puVar1 = &DAT_0087aad8;
  do {
    iVar2 = iVar2 + 1;
    _sprintf(local_104,"boost0%i",iVar2);
    FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar1,local_104,1);
    puVar1 = puVar1 + 3;
  } while ((int)puVar1 < 0x87ab50);
  if ((DAT_0093b2a4 == 0) &&
     ((*(byte *)(*(short *)(*(int *)(param_1 + 0x128) + 0x62) * 0x2e28 + 0x2800 + DAT_0087b2cc) & 1)
      == 0)) {
    puVar1 = &DAT_0087aad8;
    do {
      iVar2 = FUN_005cfac0(puVar1);
      if (iVar2 != 0) {
        FUN_005cfc00(puVar1,0);
      }
      puVar1 = puVar1 + 3;
    } while ((int)puVar1 < 0x87aba4);
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  }
  puVar1 = &DAT_0087aad8;
  do {
    iVar2 = FUN_005cfac0(puVar1);
    if (iVar2 != 0) {
      FUN_005cfc00(puVar1,1);
    }
    puVar1 = puVar1 + 3;
  } while ((int)puVar1 < 0x87ab50);
  DAT_0087aa20 = 2;
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

