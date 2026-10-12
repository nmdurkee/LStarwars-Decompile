/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cdde0; label: FUN_006cdde0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cdde0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 in_ECX;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  piVar1 = (int *)FUN_006c7170(0,0,0);
  if (piVar1 != (int *)0x0) {
    FUN_006c6700(piVar1,in_ECX);
    uVar4 = 0x80;
    puVar3 = local_84;
    uVar2 = (**(code **)(*piVar1 + 0xc))(puVar3,0x80);
    FUN_006c9760(uVar2,puVar3,uVar4);
    (**(code **)(*piVar1 + 0x10))(local_84);
    piVar1[2] = param_1;
  }
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

