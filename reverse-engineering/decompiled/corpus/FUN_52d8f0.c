/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x52d8f0; label: FUN_0052d8f0
 */

undefined4
FUN_0052d8f0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = param_4;
  iVar7 = 0;
  iVar5 = 0;
  iVar6 = 0;
  uVar1 = 0;
  if (((param_1 != 0) && (param_6 != 0)) && (0 < param_5)) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(iVar2 + iVar7 * 4),&DAT_00757f40);
      if (iVar3 == 0) {
        iVar3 = FUN_004f8a70(*(undefined4 *)(iVar2 + iVar7 * 4),&DAT_00757d6c);
        if (iVar3 == 0) {
          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + iVar7 * 4),&DAT_0075b880);
          if (iVar3 == 0) {
            uVar1 = 1;
          }
        }
        else {
          iVar6 = iVar3 + 3;
        }
      }
      else {
        iVar5 = iVar3 + 5;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_5);
    if (((iVar5 != 0) && (iVar6 != 0)) &&
       ((puVar4 = (uint *)FUN_0051adf0(param_1,0,iVar5,iVar6,&param_1), puVar4 != (uint *)0x0 &&
        ((*puVar4 & 0x20000000) != 0)))) {
      *(undefined1 *)((int)puVar4 + 0x16) = uVar1;
    }
  }
  return 1;
}

