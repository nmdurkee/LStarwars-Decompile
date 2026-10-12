/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2cc0; label: FUN_004f2cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f2cc0(short *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  ushort uVar5;
  
  iVar4 = 0;
  iVar1 = 0;
  do {
    do {
      psVar3 = param_1;
      sVar2 = *psVar3;
      param_1 = psVar3 + 1;
    } while (sVar2 == 0x20);
  } while (sVar2 == 9);
  if (sVar2 == 0x2d) {
    iVar1 = -1;
  }
  else if (sVar2 != 0x2b) goto LAB_004f2cf2;
  sVar2 = *param_1;
  param_1 = psVar3 + 2;
LAB_004f2cf2:
  if (((param_3 == 0) && (param_3 = 10, sVar2 == 0x30)) &&
     ((*param_1 == 0x78 || (*param_1 == 0x58)))) {
    sVar2 = param_1[1];
    param_1 = param_1 + 1;
    param_3 = 0x10;
  }
  do {
    uVar5 = sVar2 - 0x30;
    if (9 < (ushort)(sVar2 - 0x30U)) {
      if ((ushort)(sVar2 - 0x41U) < 0x1a) {
        uVar5 = sVar2 - 0x37;
      }
      else {
        if (0x19 < (ushort)(sVar2 - 0x61U)) {
LAB_004f2d64:
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = param_1 + -1;
          }
          if (iVar1 == 0) {
            return iVar4;
          }
          return iVar1 * iVar4;
        }
        uVar5 = sVar2 - 0x57;
      }
    }
    if (param_3 <= (int)(uint)uVar5) goto LAB_004f2d64;
    iVar4 = iVar4 * param_3 + (uint)uVar5;
    sVar2 = *param_1;
    param_1 = param_1 + 1;
  } while( true );
}

