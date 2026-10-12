/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0b30; label: FUN_005c0b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c0b30(float *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = (int)(longlong)ROUND((*param_1 + 1.0) * -127.5);
  iVar2 = local_8;
  local_8 = (int)(longlong)ROUND(param_2 * -255.0);
  iVar1 = local_8 * 0x100;
  local_8 = (int)(longlong)ROUND((param_1[1] + 1.0) * -127.5);
  iVar2 = (iVar2 + iVar1) * 0x100 + local_8;
  local_8 = (int)(longlong)ROUND((param_1[2] + 1.0) * 127.5);
  return local_8 + iVar2 * -0x100;
}

