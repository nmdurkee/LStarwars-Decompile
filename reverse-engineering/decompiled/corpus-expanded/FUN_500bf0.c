/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500bf0; label: FUN_00500bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00500bf0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint *in_ECX;
  int *in_EDX;
  
  puVar1 = (undefined4 *)0x0;
  if (((in_EDX != (int *)0x0) && (*in_EDX != 0)) && (in_ECX != (uint *)0x0)) {
    puVar1 = (undefined4 *)(*in_ECX + 0xf & 0xfffffff0);
    *in_ECX = (uint)(puVar1 + 4);
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    uVar2 = *in_ECX + 0xf & 0xfffffff0;
    *in_ECX = uVar2;
    puVar1[1] = uVar2;
    *in_ECX = *in_ECX + *in_EDX * 4;
    _memset((void *)puVar1[1],0,*in_EDX * 4);
  }
  return puVar1;
}

