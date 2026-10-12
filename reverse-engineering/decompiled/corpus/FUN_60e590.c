/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60e590; label: FUN_0060e590
 */

void FUN_0060e590(undefined4 param_1,int param_2,int param_3,int param_4,char param_5)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
LAB_0060e5c4:
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
      puVar1[0xe] = puVar1[0xe] + param_4;
      puVar1[0x10] = puVar1[0x10] + 1;
      goto LAB_0060e5c4;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

