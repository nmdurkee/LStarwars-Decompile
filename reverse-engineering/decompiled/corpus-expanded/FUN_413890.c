/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x413890; label: FUN_00413890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413890(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  *(undefined4 *)(in_EAX + 0x63724) = *(undefined4 *)(in_EAX + 0x63720);
  *(float *)(in_EAX + 0x6371c) = *(float *)(in_EAX + 0x6371c) + _DAT_00925018;
  *(float *)(in_EAX + 0x63720) =
       *(float *)(in_EAX + 0x63728) * _DAT_00925018 + *(float *)(in_EAX + 0x63720);
  FUN_004136c0();
  iVar3 = 8;
  do {
    FUN_00411640(in_EAX + 0x636d0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_0040ebf0();
  iVar3 = 0x100;
  do {
    iVar4 = iVar3;
    FUN_00413470();
    iVar3 = iVar4 + -1;
  } while (iVar3 != 0);
  iVar3 = in_EAX + 0x564d0;
  iVar4 = iVar4 + 0x5f;
  do {
    iVar2 = iVar4;
    if (*(int *)(iVar3 + 0x110) != 0) {
      FUN_00410a10(iVar3,in_EAX + 0x636d0);
    }
    iVar3 = iVar3 + 0x130;
    iVar4 = iVar2 + -1;
  } while (iVar2 + -1 != 0);
  iVar3 = iVar2 + 5;
  iVar2 = iVar2 + 0x77;
  do {
    if (((DAT_0093d7f0 != 0) && (*(float *)(iVar2 + 0x7f127c) < *(float *)(DAT_0093d7f0 + 0x69c)))
       || ((DAT_0093d7f4 != 0 && (*(float *)(iVar2 + 0x7f127c) < *(float *)(DAT_0093d7f4 + 0x69c))))
       ) {
      iVar4 = *(int *)(PTR_DAT_00802c54 + 0x4698);
      iVar2 = 0;
      if (0 < *(int *)(PTR_DAT_00802c54 + 0x469c)) {
        goto LAB_004139c0;
      }
      break;
    }
    iVar2 = iVar2 + -0x14;
    iVar3 = iVar3 + -1;
  } while (iVar2 != -0x14);
  goto LAB_004139ef;
  while( true ) {
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x128;
    if (*(int *)(PTR_DAT_00802c54 + 0x469c) <= iVar2) break;
LAB_004139c0:
    iVar1 = FUN_004f8b10(iVar4,s_door_to_a2_007f1270 + iVar3 * 0x14);
    if (iVar1 == 0) {
      FUN_00575f10(iVar4);
      break;
    }
  }
LAB_004139ef:
  if (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af84) {
    return;
  }
  FUN_00411c00();
  return;
}

