/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c70a0; label: FUN_006c70a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c70a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (param_1 == 0) {
    *(undefined4 *)(in_ECX + 0x70) = 0;
    *(undefined4 *)(in_ECX + 0x74) = 0;
  }
  else {
    *(int *)(in_ECX + 0x70) = *(int *)(in_ECX + 0x70) + 1;
  }
  iVar1 = *(int *)(in_ECX + 0x74);
  do {
    if (9 < iVar1) {
      if (param_1 == 0) {
        return 0;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        return *(int *)(in_ECX + 0x98);
      }
      return *(int *)(param_1 + 0x2c);
    }
    if (*(int *)(in_ECX + 0x70) < *(int *)(in_ECX + 0x44 + *(int *)(in_ECX + 0x74) * 4)) {
      do {
        iVar1 = *(int *)(in_ECX + 0x70) * 0x2c;
        if (*(int *)(*(int *)(in_ECX + 0x1c + *(int *)(in_ECX + 0x74) * 4) + 0x28 + iVar1) == 0) {
          if (*(char *)(in_ECX + 0x78) == '\0') {
LAB_006c713d:
            return *(int *)(in_ECX + 0x70) * 0x2c +
                   *(int *)(in_ECX + 0x1c + *(int *)(in_ECX + 0x74) * 4);
          }
          uVar2 = (**(code **)(*(int *)(*(int *)(in_ECX + 0x1c + *(int *)(in_ECX + 0x74) * 4) +
                                       iVar1) + 0xc))(in_ECX + 0x78);
          iVar1 = FUN_004f8a70(uVar2);
          if (iVar1 == 0) goto LAB_006c713d;
        }
        *(int *)(in_ECX + 0x70) = *(int *)(in_ECX + 0x70) + 1;
      } while (*(int *)(in_ECX + 0x70) < *(int *)(in_ECX + 0x44 + *(int *)(in_ECX + 0x74) * 4));
    }
    *(int *)(in_ECX + 0x74) = *(int *)(in_ECX + 0x74) + 1;
    *(undefined4 *)(in_ECX + 0x70) = 0;
    iVar1 = *(int *)(in_ECX + 0x74);
  } while( true );
}

