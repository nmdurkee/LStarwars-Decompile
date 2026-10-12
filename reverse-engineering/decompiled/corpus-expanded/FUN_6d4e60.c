/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d4e60; label: FUN_006d4e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d4e60(uint param_1,int param_2,int param_3,int param_4,undefined2 param_5)

{
  char *pcVar1;
  int in_ECX;
  int iVar2;
  
  if (param_1 < 0x20) {
    iVar2 = 0;
    pcVar1 = (char *)(in_ECX + 0x67f1);
    do {
      if (param_2 == pcVar1[-1]) {
        if ((-1 < param_3) && (param_3 == *pcVar1)) {
          return;
        }
        if ((-1 < param_4) && (param_4 == pcVar1[1])) {
          return;
        }
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 6;
    } while (iVar2 < 0x20);
    iVar2 = in_ECX + param_1 * 6;
    *(undefined1 *)(iVar2 + 0x67f0) = (undefined1)param_2;
    *(undefined1 *)(iVar2 + 0x67f1) = (undefined1)param_3;
    *(char *)(in_ECX + (param_1 * 3 + 0x33f9) * 2) = (char)param_4;
    *(undefined2 *)(iVar2 + 0x67f4) = param_5;
  }
  return;
}

