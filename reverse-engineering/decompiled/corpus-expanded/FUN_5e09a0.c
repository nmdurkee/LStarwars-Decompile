/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e09a0; label: FUN_005e09a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e09a0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (in_EAX != (byte *)0x0) {
    do {
      FUN_005e05e0(in_EAX,iVar1,param_2,param_3,param_4);
      if (((param_1 & 1) == 0) || (in_EAX[1] != 1)) {
        in_EAX = in_EAX + 0x10;
      }
      else {
        in_EAX = *(byte **)(in_EAX + 4);
      }
      iVar1 = iVar1 + 1;
    } while ((uint)*in_EAX != (-(uint)((param_1 & 2) != 0) & 0xfffffff6) + 0x8e);
    FUN_005e05e0(in_EAX,iVar1,param_2,param_3,param_4);
  }
  return;
}

