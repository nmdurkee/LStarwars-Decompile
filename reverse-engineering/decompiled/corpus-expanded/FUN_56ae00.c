/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56ae00; label: FUN_0056ae00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056ae00(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *(uint *)(iVar1 + 0x94) =
         *(uint *)(iVar1 + 0x94) ^
         ((uint)(param_2 != 0) << 0x17 ^ *(uint *)(iVar1 + 0x94)) & 0x800000;
    iVar2 = FUN_005d0420(*(int *)(iVar1 + 0xa4) + 0x30);
    if (iVar2 != 0) {
      if (param_2 == 0) {
        *(uint *)(iVar2 + 0x50) = *(uint *)(iVar2 + 0x50) & 0xfffffffe;
        return;
      }
      if ((*(uint *)(iVar1 + 0x94) & 0x100000) != 0) {
        *(uint *)(iVar2 + 0x50) = *(uint *)(iVar2 + 0x50) | 1;
      }
    }
    if (param_2 != 0) {
      FUN_00566ba0();
    }
  }
  return;
}

