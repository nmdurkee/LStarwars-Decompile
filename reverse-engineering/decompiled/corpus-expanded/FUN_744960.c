/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x744960; label: FUN_00744960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00744960(undefined4 param_1)

{
  undefined1 *in_ECX;
  undefined1 uVar1;
  undefined1 uVar2;
  
  uVar2 = (undefined1)((uint)param_1 >> 0x10);
  in_ECX[2] = uVar2;
  *in_ECX = (char)param_1;
  in_ECX[4] = (char)param_1;
  uVar1 = (undefined1)((uint)param_1 >> 0x18);
  in_ECX[3] = uVar1;
  in_ECX[7] = uVar1;
  uVar1 = (undefined1)((uint)param_1 >> 8);
  in_ECX[1] = uVar1;
  in_ECX[5] = uVar1;
  in_ECX[6] = uVar2;
  return;
}

