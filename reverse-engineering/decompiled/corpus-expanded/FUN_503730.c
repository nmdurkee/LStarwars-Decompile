/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x503730; label: FUN_00503730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

