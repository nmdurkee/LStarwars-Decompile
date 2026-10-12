/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c0b30; label: FUN_005c0b30
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

