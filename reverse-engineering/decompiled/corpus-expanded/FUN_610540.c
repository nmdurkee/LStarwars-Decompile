/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x610540; label: FUN_00610540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610540(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      cVar1 = *param_1;
      cVar2 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      if (cVar1 != cVar2) {
        return;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
  }
  return;
}

