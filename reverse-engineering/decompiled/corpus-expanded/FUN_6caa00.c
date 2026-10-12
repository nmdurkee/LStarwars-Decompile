/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6caa00; label: FUN_006caa00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006caa00(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  if (DAT_0081fa94 != (int *)0x0) {
    piVar2 = DAT_0081fa94;
    while (piVar2[3] != *(int *)(in_ECX + 0xc)) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        return 1;
      }
    }
    local_c = piVar2[2];
    local_8 = piVar2[3];
    if (local_8 != 0) {
      local_4 = *(undefined4 *)(in_ECX + 8);
      iVar1 = FUN_006e6b90();
      FUN_006c9bf0(&local_c,2 - (uint)(iVar1 != 0));
      if (DAT_0081fa94 != (int *)0x0) {
        piVar2 = DAT_0081fa94;
        do {
          if (piVar2[3] == *(int *)(in_ECX + 0xc)) {
            return 1;
          }
          piVar2 = (int *)*piVar2;
        } while (piVar2 != (int *)0x0);
      }
      FUN_006c9bf0(&local_c,1);
    }
  }
  return 1;
}

