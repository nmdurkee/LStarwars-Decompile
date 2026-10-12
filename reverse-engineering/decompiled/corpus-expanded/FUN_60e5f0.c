/* Ghidra pseudocode, not original source.
 * ev_168b65d5705473c04d5f4e526193e1abf552a66e90d2db36f509f2a3124060c2
 * Entry: 0x60e5f0; label: FUN_0060e5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060e5f0(undefined4 param_1,int param_2,int param_3,int param_4,char param_5)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
LAB_0060e624:
      if (param_2 != 0) {
        if (1 < *(uint *)(param_2 + 0x4b0)) {
          *(uint *)(param_2 + 0x4b0) = *(uint *)(param_2 + 0x4b0) - 1;
          return;
        }
        *(undefined4 *)(param_2 + 0x4b0) = 0;
      }
      return;
    }
    if (*(char *)(puVar1 + 3) == param_5) {
      if (param_2 == 0) {
        param_4 = 0;
      }
      else {
        param_4 = param_4 - param_3;
      }
      puVar1[0xf] = puVar1[0xf] + param_4;
      puVar1[0x11] = puVar1[0x11] + 1;
      goto LAB_0060e624;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

