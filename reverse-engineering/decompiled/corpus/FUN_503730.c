/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x503730; label: FUN_00503730
 */

undefined4 * FUN_00503730(undefined4 param_1)

{
  size_t _Size;
  int iVar1;
  int *in_EAX;
  int in_ECX;
  undefined4 *puVar2;
  
  iVar1 = **(int **)(in_ECX + 0x24);
  puVar2 = (undefined4 *)(*in_EAX + 0xfU & 0xfffffff0);
  *in_EAX = (int)(puVar2 + 2);
  puVar2[1] = 0;
  *puVar2 = param_1;
  puVar2[1] = *in_EAX;
  _Size = iVar1 * 4;
  *in_EAX = *in_EAX + _Size;
  _memset((void *)puVar2[1],0,_Size);
  return puVar2;
}

