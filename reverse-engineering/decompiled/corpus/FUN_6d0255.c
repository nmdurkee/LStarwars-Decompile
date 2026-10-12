/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d0255; label: FUN_006d0255
 */

int FUN_006d0255(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  uint *puVar5;
  int iStack00000004;
  int iStack00000008;
  undefined **in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  int in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000050;
  int in_stack_00000054;
  
  puVar5 = (uint *)(unaff_EBP + 0x350);
  iStack00000004 = in_EAX;
  iStack00000008 = in_EAX;
  do {
    FUN_006b9450();
    _sprintf((char *)(unaff_EBP + 0x94c),"%s/%s.led",puVar5 + -0x21,puVar5 + -0x29);
    if (((*puVar5 & 2) != 0) && ((char *)(unaff_EBP + 0x94c) != (char *)0x0)) {
      iVar1 = *(int *)(unaff_EBP + 0xa5c);
      *(int *)(unaff_EBP + 0xa58) = iVar1;
      iVar2 = FUN_004f02d0(iVar1,*(int *)(unaff_EBP + 0xa60) - iVar1,1);
      if (iVar2 != 0) {
        in_stack_00000024 = 0;
        in_stack_00000028 = 0;
        in_stack_0000001c = 0;
        in_stack_0000002c = 0;
        in_stack_00000018 = 2;
        in_stack_00000010 = &PTR_LAB_0076f9ac;
        in_stack_00000050 = 0;
        in_stack_00000014 = 4;
        in_stack_00000054 = iVar2;
        iVar3 = FUN_006c8480("StreamInfo");
        if (iVar3 != 0) {
          (*(code *)in_stack_00000010[2])(&stack0x00000014,4,1);
          (**(code **)(iStack00000004 + 0x1c))();
        }
        in_stack_00000020 = iStack00000004;
        FUN_006cb820(&stack0x00000010);
        uVar4 = FUN_004f6d10(iVar2);
        in_stack_00000054 = 0;
        FUN_004f99e0(iVar2);
        iVar2 = FUN_004fa5f0(unaff_EBP + 0x94c,1);
        if (iVar2 != 0) {
          FUN_004f03d0(iVar2,iVar1,uVar4);
          FUN_004f99e0(iVar2);
          *puVar5 = *puVar5 | 4;
          iStack00000008 = 1;
          goto LAB_006d03ab;
        }
        *puVar5 = *puVar5 & 0xfffffffb;
      }
      FUN_006b7c50(unaff_EBP + 0x94c);
    }
LAB_006d03ab:
    iStack00000004 = iStack00000004 + 1;
    puVar5 = puVar5 + 0x2a;
    if (9 < iStack00000004) {
      FUN_006b9490();
      return iStack00000008;
    }
  } while( true );
}

