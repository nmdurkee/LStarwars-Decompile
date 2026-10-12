/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4e9980; label: FUN_004e9980
 */

void FUN_004e9980(void)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_10 [12];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_10;
  if (DAT_0088a302 == '\0') goto switchD_004e99b4_default;
  switch(DAT_0088a301) {
  case 1:
    DAT_0088a30c = DAT_007f18b4;
    pcVar2 = "Probe";
    break;
  case 2:
    DAT_0088a30c = DAT_007f18f8;
    pcVar2 = "rider";
    break;
  case 3:
    DAT_0088a30c = DAT_007f1914;
    DAT_0088a320 = 2;
    pcVar2 = "ATAT";
    goto LAB_004e99ce;
  case 4:
    DAT_0088a30c = DAT_007f18b4;
    DAT_0088a320 = 4;
    DAT_0088a321 = 4;
    FUN_004f1f10(&DAT_0088a323,"Probe");
    DAT_0088a334._0_2_ = DAT_007f18f8;
    DAT_0088a348 = 6;
    DAT_0088a349 = 6;
    FUN_004f1f10(&DAT_0088a34b,"rider");
    DAT_0088a35c = DAT_007f1914;
    DAT_0088a370 = 1;
    DAT_0088a371 = 1;
    FUN_004f1f10(&DAT_0088a373,&DAT_0075e464);
    DAT_0088a3c4 = 3;
  default:
    goto switchD_004e99b4_default;
  }
  DAT_0088a320 = 0xb;
LAB_004e99ce:
  DAT_0088a321 = DAT_0088a320;
  FUN_004f1f10(&DAT_0088a323,pcVar2);
  DAT_0088a3c4 = 1;
switchD_004e99b4_default:
  DAT_0088a302 = 0;
  if (DAT_00855de0 == 0) {
    iVar1 = 0;
    if (DAT_0088a3c4 != 0) {
      do {
        FUN_004e94c0(iVar1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)DAT_0088a3c4);
    }
    __security_check_cookie(local_4 ^ (uint)auStack_10);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)auStack_10);
  return;
}

