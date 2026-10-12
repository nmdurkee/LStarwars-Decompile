/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x4416b0; label: FUN_004416b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004416b0(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = *(int *)(*(int *)(in_stack_00000014 + 4) + 0x144);
    if (iVar1 == 0) {
      if (((*(uint *)(in_stack_00000014 + 0x1fc) & 0x1000) != 0) &&
         (*(char *)(in_stack_00000014 + 0x28b) == '\0')) {
LAB_00441704:
        return (float10)1;
      }
    }
    else {
      iVar4 = 0;
      if (*(byte *)(iVar1 + 7) != 0) {
        piVar3 = (int *)(iVar1 + 0xc);
        do {
          if (*piVar3 != 0) {
            uVar2 = *(uint *)(*piVar3 + 0x1fc);
            if ((((uVar2 & 1) != 0) && ((uVar2 & 0x1000) != 0)) &&
               (*(char *)(*piVar3 + 0x28b) == '\0')) goto LAB_00441704;
          }
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 1;
          if ((int)(uint)*(byte *)(iVar1 + 7) <= iVar4) {
            return (float10)0;
          }
        } while( true );
      }
    }
  }
  return (float10)0;
}

