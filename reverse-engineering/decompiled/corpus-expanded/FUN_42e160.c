/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42e160; label: FUN_0042e160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042e160(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 uVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  int local_8;
  int local_4;
  
  DAT_0093b2e8 = 6;
  if (DAT_007f39e4 != 0) {
    DAT_0093b310 = 0xe;
  }
  DAT_0093b308 = 1;
  DAT_0093b304 = 1;
  DAT_0093b300 = 1;
  DAT_0093b2fc = 2;
  DAT_0093b2f8 = 1;
  DAT_0093b2f4 = 2;
  DAT_0093b2f0 = 2;
  DAT_0093b2ec = 2;
  DAT_0093b2e4 = 1;
  DAT_0093b2e0 = 3;
  DAT_0093b2dc = 3;
  DAT_0093b2d8 = 1;
  DAT_00880150 = 0;
  if (DAT_007fcb48 != -1) {
    psVar9 = &DAT_007fcb48;
    do {
      if (0x17 < DAT_00880150) break;
      puVar4 = (undefined2 *)FUN_00576480((int)*psVar9);
      if (puVar4 != (undefined2 *)0x0) {
        (&DAT_007fcb18)[DAT_00880150] = *puVar4;
        DAT_00880150 = DAT_00880150 + 1;
        if (*(int *)(puVar4 + 2) != 0) {
          DAT_0093b2b8 = DAT_0093b2b8 + DAT_0093b304;
          _DAT_0093b2d0 = _DAT_0093b2d0 + DAT_0093b304;
        }
      }
      psVar9 = psVar9 + 1;
    } while (*psVar9 != -1);
  }
  iVar8 = 0;
  DAT_0093b314 = 0;
  DAT_0093b318 = 1;
  DAT_0093b31c = 0;
  DAT_0093b320 = 0;
  if (0 < DAT_00956294) {
    DAT_0093b2b8 = DAT_0093b2b8 + DAT_00956294 * DAT_0093b2dc;
    _DAT_0093b2bc = _DAT_0093b2bc + DAT_00956294 * DAT_0093b2dc;
  }
  if (0 < DAT_00951360) {
    local_4 = 0;
    iVar10 = DAT_00951354;
    do {
      uVar3 = FUN_0059b620(iVar8,&local_8);
      *(undefined1 *)(iVar10 + 0x86) = uVar3;
      *(undefined1 *)(iVar10 + 0x87) = (undefined1)local_8;
      if (((iVar10 != DAT_00951364) && (uVar2 = *(ushort *)(iVar10 + 0x7a), (uVar2 & 0x22) == 0)) &&
         ((uVar2 & 0x2000) == 0)) {
        if ((uVar2 & 0x100) == 0) {
          if ((uVar2 & 4) == 0) {
            DAT_0093b2b8 = DAT_0093b2b8 + DAT_0093b2e8;
            DAT_0093b2c0 = DAT_0093b2c0 + DAT_0093b2e8;
            if ((*(ushort *)(iVar10 + 0x7a) & 0x800) == 0) {
              DAT_0093b30c = DAT_0093b30c + 1;
            }
            iVar6 = DAT_0093b30c;
            if ((*(byte *)(local_4 + 0x7a + DAT_00951354) & 0x10) != 0) {
              DAT_0093b30c = DAT_0093b30c + 2;
              iVar5 = DAT_0093b2b8 + DAT_0093b2f4 + DAT_0093b2f0;
              iVar7 = DAT_0093b2c0 + DAT_0093b2f0 + DAT_0093b2f4;
              if (DAT_0093b314 != 0) {
                iVar5 = iVar5 + DAT_0093b2f4;
                iVar7 = iVar7 + DAT_0093b2f4;
                DAT_0093b30c = iVar6 + 3;
              }
              DAT_0093b2b8 = iVar5 + DAT_0093b2f8 + DAT_0093b2ec;
              DAT_0093b2c0 = iVar7 + DAT_0093b2f8 + DAT_0093b2ec;
              if (DAT_0093b320 != 0) {
                DAT_0093b30c = DAT_0093b30c + 1;
              }
            }
          }
          else {
            DAT_0093b2b8 = DAT_0093b2b8 + DAT_0093b2e4;
            DAT_0093b2c0 = DAT_0093b2c0 + DAT_0093b2e4;
            DAT_0093b30c = DAT_0093b30c + 1;
          }
        }
        else {
          DAT_0093b2b8 = DAT_0093b2b8 + DAT_0093b2e0;
          DAT_0093b2c0 = DAT_0093b2c0 + DAT_0093b2e0;
          if (DAT_0093b318 != 0) {
            DAT_0093b30c = DAT_0093b30c + 1;
          }
        }
        if (*(char *)(iVar10 + 0x7e) != -1) {
          FUN_0056e580((int)*(char *)(iVar10 + 0x7e),iVar8);
        }
      }
      local_4 = local_4 + 0x9c;
      iVar8 = iVar8 + 1;
      iVar10 = iVar10 + 0x9c;
    } while (iVar8 < DAT_00951360);
  }
  iVar8 = 0;
  if (0 < DAT_00951b84) {
    psVar9 = (short *)(DAT_00951b78 + 0x60);
    do {
      if ((*psVar9 < 0) || (799 < *psVar9)) {
        *psVar9 = DAT_008806a0;
      }
      *(undefined1 *)((int)psVar9 + 0x43) = 0xff;
      *(undefined1 *)(psVar9 + 0x34) = 0xff;
      local_8 = 0;
      cVar1 = *(char *)((int)psVar9 + 0x43);
      iVar10 = DAT_00951354;
      for (; (cVar1 == -1 && (local_8 < DAT_00951360)); local_8 = local_8 + 1) {
        cVar1 = *(char *)((int)psVar9 + 0x43);
        for (iVar6 = 0;
            (cVar1 == -1 && (iVar6 < (int)(uint)*(byte *)(iVar10 + 0x7d + local_8 * 0x9c)));
            iVar6 = iVar6 + 1) {
          if (*(short *)(iVar10 + 0x60 + (local_8 * 0x4e + iVar6) * 2) == iVar8) {
            *(char *)((int)psVar9 + 0x43) = (char)local_8;
            *(char *)(psVar9 + 0x34) = (char)iVar6;
            iVar10 = DAT_00951354;
          }
          cVar1 = *(char *)((int)psVar9 + 0x43);
        }
        cVar1 = *(char *)((int)psVar9 + 0x43);
      }
      if (*(char *)((int)psVar9 + 0x43) != -1) {
        iVar6 = *(char *)((int)psVar9 + 0x43) * 0x9c;
        *(undefined1 *)(psVar9 + 0x21) = *(undefined1 *)(iVar6 + 0x86 + iVar10);
        if ((*(byte *)(iVar6 + 0x7a + DAT_00951354) & 1) != 0) {
          *(undefined1 *)((int)psVar9 + 0x6d) = 0x32;
          *(undefined1 *)(psVar9 + 0x37) = 0x14;
        }
        if ((((char)psVar9[0x21] != -1) && ((*(ushort *)(iVar6 + 0x7a + DAT_00951354) & 0x106) == 0)
            ) && ((*(uint *)(psVar9 + 2) & 0x4e0) == 0)) {
          *(uint *)(psVar9 + 2) = *(uint *)(psVar9 + 2) | 0x2000;
        }
      }
      iVar8 = iVar8 + 1;
      psVar9 = psVar9 + 0x98;
    } while (iVar8 < DAT_00951b84);
  }
  FUN_005788d0(&PTR_s_max_tightropes_007fa608,&DAT_0087b2e8);
  FUN_004cc8e0();
  FUN_005942b0("chars\\collection.txt",&DAT_00924878,&DAT_0092487c);
  if (((DAT_007f17d4 != -1) && (iVar8 = FUN_00594250((int)DAT_007f17d4,0,0), iVar8 != -1)) &&
     (DAT_00955884 != 0)) {
    *(undefined1 *)(DAT_00955884 + 2) = 0;
    *(undefined1 *)(DAT_00955884 + 8) = 1;
    *(undefined4 *)(DAT_00955884 + 4) = 50000;
  }
  DAT_0093b2b8 = DAT_0093b2b8 + DAT_00955880 * DAT_0093b2d8;
  _DAT_0093b2c4 = _DAT_0093b2c4 + DAT_00955880 * DAT_0093b2d8;
  if (DAT_007f39e4 == 0) {
    DAT_0087a7d8 = FUN_004bbd10;
    _DAT_00802bd4 = 8;
    DAT_007f17a4 = 1;
    FUN_00509660(0,0xff,0,0xff,0xbf,0,0,0x7f,0xff,0xff,0,0x1f,0xff,0xff,0xff,0xaf,0xaf,0xaf);
    DAT_007facbc = 0;
    DAT_007facbd = 0xff;
    DAT_0087b728 = 0;
    DAT_007facbe = 0xff;
    DAT_007facbf = 0;
    DAT_0087b729 = 0;
    DAT_007facc0 = 0x80;
    DAT_007facc1 = 0xff;
    DAT_007facc2 = 0;
    DAT_0087b72a = 0;
    DAT_007facc3 = 0x50;
    DAT_0095073c = 1;
    DAT_00955b1c = 1;
    FUN_0057e260(&DAT_007f3a34);
    DAT_00925160 = FUN_0041aec0;
    FUN_0062d4a0(FUN_0055b260,&DAT_00855f6c,"chars\\commonanims");
    FUN_00572360(&DAT_008034c4);
    FUN_00572370(&DAT_0095100c);
    DAT_0093d820 = 0;
    FUN_00580ca0(&PTR_DAT_007f3a60);
    FUN_00548f20(&DAT_007fc7b8);
    _DAT_00950c50 = 0x3cf9db23;
    _DAT_00803068 = 2;
    _DAT_00804dc4 = 0x3e99999a;
    DAT_0093b2b0 = FUN_00404e30;
    DAT_00803990 = 3;
    _DAT_00804dc8 = 0x3f19999a;
  }
  else {
    DAT_009553d4 = FUN_0058a540("levels\\missions.txt",&DAT_00924878,&DAT_0092487c,&DAT_0086e55c);
    if (DAT_009553d4 != 0) {
      DAT_0093b2b8 = DAT_0093b2b8 + (uint)*(byte *)(DAT_009553d4 + 0x1c) * DAT_0093b2fc;
      _DAT_0093b2c8 = _DAT_0093b2c8 + (uint)*(byte *)(DAT_009553d4 + 0x1c) * DAT_0093b2fc;
      DAT_0093b30c = DAT_0093b30c + (uint)*(byte *)(DAT_009553d4 + 0x1c);
    }
    DAT_0087a7d8 = (code *)&LAB_004bc0b0;
    _DAT_007ef3b0 = 0x5d;
    _DAT_007ef3b2 = 0x5e;
    _DAT_007ef454 = 0x5f;
    _DAT_007ef456 = 0x60;
    _DAT_007ef4f8 = 0x61;
    _DAT_007ef4fa = 0x62;
    _DAT_00802bd4 = 4;
    DAT_007f17a4 = 0;
    FUN_0057e260(&DAT_007f3a2c);
    DAT_0092134c = 1;
    FUN_0054a180(&PTR_s_deathstarbattle_d_007f1158);
    FUN_0062d4a0(FUN_0055b260,&PTR_s_ride_bantha_new_blasterchar_007f2228,"chars\\commonanims");
    FUN_00572370(&DAT_008034c4);
    FUN_00572360(&DAT_0095100c);
    DAT_0093d820 = 1;
    FUN_00580ca0(&PTR_DAT_007f3a40);
    FUN_00548f20(&PTR_FUN_007fc5b8);
    _DAT_0080525c = 0;
    _DAT_00805264 = 0;
    _DAT_00950f74 = 1;
    _DAT_0095074c = 1;
    _DAT_00804dc4 = 0x3e99999a;
    DAT_00805cb4 = 0x83;
    _DAT_00804dc8 = 0x3e99999a;
    DAT_00805cb8 = 0x49;
    DAT_00805cbc = 0x4a;
    DAT_00805cc0 = 0x4b;
    _DAT_007fc324 = 0;
    DAT_00803988 = 0x266;
    DAT_0080398c = 0x267;
    _DAT_007fc328 = 0xbf000000;
    DAT_00803990 = 0x25c;
    DAT_00803998 = 600;
    _DAT_007fc32c = 0x3fa00000;
    DAT_009505cc = 1;
    DAT_009505d0 = 1;
    _DAT_007fc330 = 0;
    DAT_00804dcc = 0;
    DAT_00924de0 = FUN_004296c0;
    DAT_00924de4 = FUN_00429700;
    DAT_0095660c = FUN_004299c0;
    DAT_009543fc = FUN_00429b80;
    DAT_0093d508 = FUN_00429bc0;
    DAT_0095559c = FUN_004295c0;
    DAT_009555a4 = FUN_00429680;
    DAT_009555a0 = FUN_004294d0;
    DAT_00924dcc = FUN_00429740;
    FUN_005a8590(&DAT_007f3afc);
    _DAT_008051b4 = 0x40000000;
    DAT_0093b100 = FUN_00429c00;
    _DAT_008051b8 = 0x3fc00000;
    DAT_00955fb4 = 1;
    DAT_00951ca0 = FUN_00429f80;
    _DAT_008051bc = 0x3f800000;
    FUN_005a8390(&PTR_DAT_007f3b18);
    _DAT_007fc04c = 0x40600000;
    DAT_0087b904 = 1;
    _DAT_007fc050 = 0x40200000;
    DAT_0087b908 = 1;
    DAT_0087b90c = 1;
    DAT_00955b20 = 1;
  }
  DAT_00804be4 = 1;
  DAT_00804c74 = 0x5f;
  DAT_00955b30 = FUN_004982b0;
  _DAT_00802d10 = FUN_00429100;
  DAT_00947bb0 = FUN_0048f6c0;
  DAT_00947bb4 = FUN_0048f6f0;
  _DAT_00803560 = 0x15;
  _DAT_0080356c = 0x16;
  DAT_00804be8 = 0;
  DAT_00804bec = 6;
  DAT_00804bf0 = 7;
  DAT_00804bf4 = 9;
  DAT_00804bf8 = 0xe;
  DAT_00804bfc = 10;
  DAT_00804c00 = 0x15;
  DAT_00804c04 = 0x12;
  DAT_00804c08 = 0x13;
  DAT_00804c0c = 5;
  DAT_00804c10 = 0x59;
  DAT_00804c14 = 0xb3;
  DAT_00804c18 = 0x41;
  DAT_00804c1c = 0x94;
  DAT_00804c20 = 0x5b;
  DAT_00804c24 = 0x5a;
  DAT_00804c28 = 0x5c;
  DAT_00804c2c = 0xda;
  DAT_00804c30 = 0x9d;
  DAT_00804c34 = 0x9e;
  DAT_00804c38 = 0x9f;
  DAT_00804c3c = 0x91;
  DAT_00804c40 = 0x92;
  DAT_00804c44 = 0x87;
  DAT_00804c48 = 0xcd;
  DAT_00804c4c = 0xce;
  DAT_00804c50 = 0xcf;
  DAT_00804c54 = 0xd0;
  DAT_00804c58 = 0x8a;
  DAT_00804c5c = 0x8b;
  DAT_00804c60 = 0x8c;
  DAT_00804c64 = 0x52;
  DAT_00804c68 = 0xae;
  DAT_00804c6c = 0xaf;
  DAT_00804c70 = 0xb0;
  DAT_00804c78 = 0xc;
  DAT_00804c7c = 0xd;
  DAT_00804c80 = 0x77;
  DAT_00804c84 = 0xa1;
  DAT_00804c88 = 0xba;
  DAT_00804c8c = 0xbb;
  DAT_00804c90 = 0xbc;
  DAT_00804c94 = 0xbd;
  DAT_00804c98 = 0x93;
  DAT_00804c9c = 0xa3;
  DAT_00804ca0 = 0xa4;
  DAT_00804ca4 = 0xa5;
  DAT_00804ca8 = 0xa6;
  DAT_00804cac = 0xd5;
  DAT_00804cb0 = 0xd6;
  DAT_00804cb4 = 0xd7;
  DAT_00804cb8 = 0xd8;
  DAT_00804cbc = 0xd9;
  DAT_00804cc0 = 0xc5;
  _DAT_00804cc4 = 0xc6;
  _DAT_00804cc8 = 199;
  _DAT_00804ccc = 200;
  DAT_00804cd0 = 0xc9;
  _DAT_00804cd4 = 0xca;
  DAT_00804cd8 = 0x1f;
  DAT_00804cdc = 0x20;
  DAT_00804ce0 = 0x21;
  DAT_00804ce4 = 0x22;
  DAT_00804ce8 = 0xb4;
  DAT_00804cec = 0xb5;
  DAT_00804cf0 = 0xb6;
  DAT_00804cf4 = 0x57;
  DAT_00804cf8 = 0x78;
  _DAT_0080283c = 0x1f;
  DAT_00804d14 = 0xdd;
  DAT_00804d18 = 0xdd;
  DAT_00804d1c = 0xdd;
  DAT_0080281c = 0xc;
  DAT_00802844 = 5;
  DAT_00802848 = 0x26;
  DAT_008028a0 = 0x26;
  DAT_00803b70 = 5;
  DAT_00804cfc = 0x79;
  DAT_00804d00 = 0x7a;
  DAT_00804d04 = 0x7b;
  DAT_00804d08 = 0x2a;
  _DAT_00804d0c = 0xdb;
  DAT_00804d10 = 0xdc;
  DAT_00804d20 = 0xe0;
  DAT_00804d24 = 0xe1;
  DAT_00804d28 = 0xe2;
  DAT_00802814 = 0x11;
  DAT_00802818 = 0x4f;
  DAT_00802820 = 0x18;
  DAT_00802824 = 0x23;
  DAT_00802828 = 0x2b;
  _DAT_0080282c = 0x55;
  DAT_00802830 = 0x43;
  _DAT_00802834 = 0x4e;
  DAT_00802838 = 0;
  DAT_00802840 = 0x45;
  DAT_0080284c = 0x27;
  DAT_00802850 = 0x28;
  DAT_00802854 = 0x59;
  DAT_00802858 = 0x3b;
  DAT_0080285c = 0x3c;
  _DAT_00802860 = 0x2d;
  DAT_00802864 = 6;
  DAT_00802868 = 7;
  DAT_0080286c = 0x20;
  DAT_00802870 = 0x57;
  DAT_00802874 = 0x46;
  DAT_00802878 = 0x58;
  DAT_0080287c = 1;
  DAT_00802880 = 2;
  DAT_00802884 = 3;
  DAT_00802888 = 4;
  DAT_0080288c = 0xd;
  _DAT_00802890 = 0xe;
  _DAT_00802894 = 0x19;
  DAT_00802898 = 0x29;
  DAT_0080289c = 0x39;
  DAT_008028a4 = 0x30;
  DAT_008028a8 = 0x3e;
  _DAT_008028ac = 0x62;
  DAT_008028b0 = 99;
  _DAT_008037f4 = 0;
  DAT_008037f8 = 1;
  DAT_008037fc = 2;
  DAT_00803804 = 0x12;
  DAT_008021b8 = 4;
  DAT_008021bc = 2;
  DAT_00803b88 = 0xa7;
  DAT_00803b8c = 0xa5;
  DAT_00803b90 = 0xa6;
  DAT_00803b94 = 0xa1;
  DAT_00803b98 = 0xa3;
  DAT_00803b9c = 0xcf;
  DAT_00803ba0 = 0xce;
  DAT_00803b74 = 0;
  _DAT_00805b40 = 0xd;
  _DAT_00804e38 = 0x4c;
  _DAT_00804e3a = 0x4d;
  _DAT_00804e3c = 0x4e;
  _DAT_00804e3e = 0x4f;
  _DAT_00804e40 = 0x50;
  _DAT_00804e42 = 0x51;
  DAT_008025bc = 0x57;
  DAT_008025c0 = 0x58;
  DAT_00926c24 = PTR_DAT_007f3a18;
  DAT_00926c28 = PTR_DAT_007f3a1c;
  DAT_008025be = 1;
  DAT_00926bd4 = FUN_0042b950;
  DAT_00951430 = FUN_00428d70;
  DAT_00950bc0 = FUN_004d5550;
  _DAT_00926c2c = PTR_DAT_007f3a20;
  _DAT_00926c30 = PTR_DAT_007f3a24;
  DAT_00926c34 = PTR_DAT_007f3a28;
  DAT_00855de4 = 1;
  DAT_00951cb4 = FUN_0042a600;
  FUN_0057e430("cut\\clips.txt",&DAT_00924878,&DAT_0092487c,&DAT_008807e4,&DAT_008807e8,
               &DAT_008807ec,&DAT_008807f0,&DAT_008807f4);
  DAT_00950d94 = (int)DAT_0088109c;
  DAT_00950c4c = &LAB_00428e20;
  DAT_0095629c = FUN_00428e40;
  DAT_00955fb0 = FUN_00428e70;
  _DAT_0095dea0 = FUN_00428ea0;
  DAT_009505e8 = &LAB_00428ed0;
  DAT_00955584 = FUN_00428ef0;
  DAT_00955598 = &LAB_00428f20;
  DAT_0093d828 = FUN_00429010;
  DAT_008025b4 = 0;
  DAT_008025b8 = 1;
  DAT_009555ac = FUN_00429050;
  DAT_0095558c = FUN_004290a0;
  DAT_00955590 = FUN_004290d0;
  DAT_00803ba4 = 0x55;
  DAT_00803ba8 = 0x3d;
  DAT_009505e4 = FUN_00428f70;
  DAT_0093d824 = FUN_00428ff0;
  DAT_00947bbc = 1;
  DAT_0093b330 = thunk_FUN_0047a910;
  DAT_0095de4c = FUN_0047aad0;
  DAT_00924df4 = FUN_0042a070;
  DAT_009555b0 = FUN_0042a1b0;
  DAT_009555b4 = FUN_0042e0c0;
  DAT_0095075c = FUN_0042a210;
  DAT_0093b344 = &LAB_0042a2f0;
  DAT_0093b348 = FUN_0042a350;
  DAT_0093d50c = FUN_0042a360;
  DAT_00924dd8 = &LAB_0042a420;
  DAT_00950778 = FUN_0042a5a0;
  DAT_009505e0 = FUN_0042a5b0;
  DAT_00950bc8 = FUN_0042a850;
  DAT_0093b0e0 = FUN_0042a5d0;
  DAT_009505d4 = FUN_0042a640;
  DAT_00951010 = FUN_0042a690;
  DAT_009514d0 = FUN_0042a740;
  DAT_007fa1c4 = 0x1f1;
  DAT_007fa1c8 = 2;
  DAT_00950f78 = FUN_0042a760;
  _DAT_00803bac = 0xb7;
  DAT_00956610 = FUN_0042a7a0;
  DAT_00955888 = FUN_0042a7d0;
  DAT_00950bc4 = FUN_0042a880;
  DAT_02913114 = thunk_FUN_005d05b0;
  DAT_02913118 = FUN_00596980;
  DAT_009505c4 = FUN_0042a920;
  DAT_009505d8 = FUN_0042a950;
  DAT_009505dc = FUN_0042a9b0;
  if (DAT_00876580 == 0) {
    if (DAT_007f39e4 == 0) {
      DAT_0093d834 = FUN_00429210;
      DAT_0093d838 = FUN_00429300;
      DAT_009555a0 = FUN_00429480;
      FUN_005a8390(&DAT_00876590);
    }
  }
  else {
    _DAT_008030e8 = 0x3d99999a;
    _DAT_00804dc4 = 0x3e99999a;
    _DAT_007fd124 = DAT_0093b0cc;
    _DAT_00804dc8 = 0x3e99999a;
    _DAT_007fd128 = DAT_0093b0d0;
    _DAT_007fd130 = DAT_0093b0cc;
    _DAT_007fd118 = 0xbe4ccccd;
    _DAT_007fd134 = DAT_0093b0d0;
    _DAT_007fd13c = 0;
    _DAT_007fd140 = 0;
    DAT_00950c48 = 1;
    DAT_008030e4 = 0;
    _DAT_007fd144 = 0xbe049ba6;
    DAT_00802454 = 1;
    DAT_00927038 = 1;
    _DAT_00803e08 = 0xbf000000;
    DAT_00955fb8 = 1;
    DAT_00955fbc = 1;
    _DAT_00803e0c = 0x3f19999a;
    DAT_00803984 = 0;
    _DAT_00803e10 = 0x3f19999a;
    DAT_007fd11e = 0x2f;
    DAT_007fd120 = 0x30;
    _DAT_008051b4 = 0x40000000;
    _DAT_007fd122 = 0x31;
    _DAT_007fd12c = DAT_0093b0d4;
    _DAT_008051b8 = 0x3fc00000;
    _DAT_007fd138 = DAT_0093b0d4;
    DAT_007fd11c = 0x56;
    DAT_007fd148 = 0xffff;
    DAT_007fd14a = 0xffff;
    _DAT_007faaa8 = 0x56;
    DAT_00955fb4 = 1;
  }
  DAT_0093b2b8 = DAT_0093b2b8 + DAT_0093b300 * 0x2c;
  iVar8 = 0x2c;
  do {
    DAT_0093b2cc = DAT_0093b2cc + DAT_0093b300;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (0 < DAT_0093b310) {
    DAT_0093b2b8 = DAT_0093b2b8 + DAT_0093b310 * DAT_0093b308;
    DAT_0093b30c = DAT_0093b30c + DAT_0093b310;
    iVar8 = DAT_0093b310;
    do {
      DAT_0093b2d4 = DAT_0093b2d4 + DAT_0093b308;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (DAT_007f39e4 != 0) {
    iVar8 = FUN_0057e700();
    DAT_0087ff90 = 0;
    if (iVar8 != 0) {
      DAT_0087ff90 = (uint)*(ushort *)(iVar8 + 8);
    }
  }
  return;
}

