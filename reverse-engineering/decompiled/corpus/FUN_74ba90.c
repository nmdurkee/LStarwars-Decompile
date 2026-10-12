/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74ba90; label: FUN_0074ba90
 */

void FUN_0074ba90(int *param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int local_22c;
  int local_228;
  int local_224;
  int local_220;
  undefined1 local_214 [16];
  undefined1 local_204 [512];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_22c;
  FUN_00740f30(local_204,0x200);
  FUN_00748460(local_214,0x200);
LAB_0074bae2:
  do {
    if (param_1[1] <= param_2) {
      FUN_00748490();
      FUN_00740e90();
      __security_check_cookie(local_4 ^ (uint)&local_22c);
      return;
    }
    iVar4 = 0;
    pcVar1 = (char *)(*param_1 + param_2);
    for (pcVar3 = pcVar1;
        (pcVar3 < (char *)(*param_1 + param_1[1]) && (iVar4 = iVar4 + 1, *pcVar3 != '\n'));
        pcVar3 = pcVar3 + 1) {
    }
    FUN_00748530(pcVar1,iVar4);
    param_2 = param_2 + iVar4;
    iVar4 = 0;
    local_228 = 0;
    if (0 < local_220) {
      do {
        cVar2 = *(char *)(local_224 + iVar4);
        if ((cVar2 != ' ') && (cVar2 != '\t')) {
          if (cVar2 == '#') {
            local_228 = iVar4 + 1;
            FUN_0074de40(&local_224,&local_228);
            local_220 = 0;
            goto LAB_0074bae2;
          }
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_220);
    }
    if (*(char *)(local_22c + 0x120) != '\0') {
      FUN_00748530(local_224,local_220);
    }
    local_220 = 0;
  } while( true );
}

