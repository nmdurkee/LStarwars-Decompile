/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cda40; label: FUN_004cda40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004cda40(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x6c) == 0) {
      FUN_004ccad0(param_1);
    }
    cVar1 = *(char *)(param_1 + 0x37);
    if (cVar1 == '\x01') {
      return *(int *)(param_1 + 0x6c) + 0x80;
    }
    if (cVar1 == '\x02') {
      iVar2 = FUN_005cf9c0();
      return iVar2;
    }
    if (cVar1 == '\x03') {
      iVar2 = FUN_0055a360(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),
                           *(undefined4 *)(param_1 + 0x6c));
      return iVar2;
    }
  }
  return 0;
}

