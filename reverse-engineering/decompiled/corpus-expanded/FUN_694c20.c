/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x694c20; label: FUN_00694c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00694c20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = 0;
  if (DAT_02962b8c != (undefined4 *)0x0) {
    uVar1 = FUN_00693b60();
  }
  in_ECX[0x75] = param_2;
  DAT_02962b8c = in_ECX;
  in_ECX[6] = 0x1000;
  *(undefined1 *)(in_ECX + 9) = uVar1;
  *(undefined1 *)(in_ECX + 0x49) = uVar1;
  FUN_00693c40();
  FUN_00694930(param_1,param_3,param_4);
  in_ECX[0x66] = 0x3f800000;
  in_ECX[0x67] = 0x3f800000;
  in_ECX[0x76] = *in_ECX;
  in_ECX[0x68] = 0x3f800000;
  in_ECX[0x69] = 0;
  in_ECX[0x6a] = 0x3f800000;
  in_ECX[0x6b] = 0x3f800000;
  in_ECX[0x6c] = 0x3f000000;
  in_ECX[0x73] = 0x3f800000;
  return 1;
}

