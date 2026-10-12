/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x491b30; label: FUN_00491b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00491b30(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = 0;
    do {
      iVar1 = FUN_004f8b10(param_2,(&PTR_s_MAINROOM_007fab24)[iVar2]);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 10);
  }
  return -1;
}

