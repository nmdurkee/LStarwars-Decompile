/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x500bf0; label: FUN_00500bf0
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

