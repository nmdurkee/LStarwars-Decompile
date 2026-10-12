/* Ghidra pseudocode, not original source.
 * ev_eea3a7cf55e62a15d31ae8423a3c3e3cacac13ee26e2c6e4adfc577ce8b80763
 * Entry: 0x745200; label: FUN_00745200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745200(undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  undefined1 local_24 [36];
  
  FUN_00744320(param_1,0,0,0);
  (**(code **)(*in_ECX + 0x18))(local_24,param_2);
  return;
}

