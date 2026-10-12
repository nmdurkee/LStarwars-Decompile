/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6caa00; label: FUN_006caa00
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

