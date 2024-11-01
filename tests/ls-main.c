__int64 __fastcall main(
        int a1,
        char **a2,
        char **a3,
        double a4,
        __m128 a5,
        __m128 a6,
        __m128 a7,
        double a8,
        double a9,
        __m128 a10,
        __m128 a11)
{
  char *v11; // rbx
  char *v12; // rax
  char *v13; // r12
  const char *v14; // r13
  __m128 si128; // xmm0
  int v16; // eax
  int v17; // edx
  char v18; // al
  _OWORD *v19; // rax
  int v20; // edx
  char v21; // al
  char *v22; // r13
  unsigned int v23; // eax
  const char *v24; // rbx
  char *v25; // rax
  char *v26; // r13
  int v27; // eax
  const char *v28; // rbx
  int v29; // esi
  int v30; // eax
  char *v31; // rbx
  char *v32; // rax
  __m128 v33; // xmm4
  __m128 v34; // xmm5
  int v35; // eax
  unsigned __int64 v36; // rax
  __int64 v37; // rax
  char v38; // al
  int v39; // ebx
  int v40; // r12d
  __m128i *v41; // rax
  char *v42; // rdi
  unsigned __int8 v43; // cl
  __int64 *v44; // rsi
  int *v45; // rdx
  int v46; // r8d
  int v47; // eax
  __m128i *v48; // rax
  __int32 v49; // ecx
  int v50; // eax
  const char *i; // r12
  int v52; // eax
  char *v53; // rax
  char v54; // al
  __int64 v55; // rax
  __int64 v56; // rbx
  char *v57; // rdi
  unsigned __int64 v58; // rsi
  void *v59; // rbx
  unsigned int **v60; // r12
  char *v61; // rdi
  void *v62; // r14
  char *v63; // rax
  int n; // ebx
  __int64 v66; // rax
  unsigned __int8 *v67; // rax
  __int64 v68; // rbx
  __int64 v69; // rax
  float v70; // xmm5_4
  __int64 v71; // rax
  float v72; // xmm4_4
  float v73; // xmm4_4
  float *v74; // rax
  float v75; // xmm5_4
  float v76; // xmm4_4
  unsigned __int64 v77; // rsi
  unsigned int *m; // rdi
  unsigned int *v79; // r15
  char *v80; // rax
  __int64 v81; // rbx
  int v82; // eax
  unsigned __int64 v83; // rax
  int v84; // edx
  bool v85; // dl
  void *v86; // r15
  char *v87; // rbx
  unsigned __int64 v88; // r14
  int *v89; // r12
  __int64 v90; // rax
  __int64 v91; // r13
  size_t v92; // rax
  unsigned __int64 v93; // rax
  char *v94; // rbx
  char *v95; // rax
  char *v96; // r12
  char v97; // al
  __int64 v98; // r12
  __int64 v99; // r14
  __int64 v100; // r12
  __int64 v101; // rbx
  __int64 v102; // r13
  const void *v103; // r12
  const void *v104; // r15
  char v105; // al
  bool v106; // zf
  __int64 v107; // r13
  const char *v108; // rsi
  __int64 *v109; // rcx
  __int64 v110; // r12
  char *v111; // rax
  char *v112; // rax
  _QWORD *j; // rdi
  size_t v114; // rdx
  char **v115; // rbx
  int v116; // edi
  char **v117; // rsi
  __int64 v118; // rax
  int v119; // edx
  const char *v120; // rcx
  int v121; // r8d
  int v122; // r9d
  __int64 v123; // rdx
  unsigned int v124; // ecx
  char *IO_write_ptr; // rax
  char *v126; // rax
  __int64 v127; // rbx
  char *v128; // rax
  char *v129; // rax
  const char *v130; // r13
  const char *k; // r14
  __int64 v132; // rdx
  _QWORD *v133; // rbx
  _BYTE *v134; // r13
  __int64 v135; // rax
  FILE *v136; // r13
  char *v137; // rax
  FILE *v138; // r13
  char *v139; // rax
  char *v140; // rax
  char *v141; // rax
  char *v142; // rbx
  __int64 v143; // rbx
  char *v144; // rax
  __int64 v145; // rbx
  char *v146; // rax
  __int64 v147; // rbx
  char *v148; // rax
  __int64 v149; // r13
  int v150; // r12d
  const char *v151; // rsi
  char *v152; // rbx
  char *v153; // r14
  char *v154; // rax
  __int64 v155; // rbx
  char *v156; // rax
  char *v157; // rax
  __int64 v158; // [rsp+0h] [rbp-130h]
  char *v159; // [rsp+8h] [rbp-128h]
  __int64 v160; // [rsp+10h] [rbp-120h]
  __int64 v161; // [rsp+18h] [rbp-118h]
  const char *s1; // [rsp+20h] [rbp-110h]
  char *s1a; // [rsp+20h] [rbp-110h]
  __int64 v164; // [rsp+28h] [rbp-108h]
  char v165; // [rsp+2Ch] [rbp-104h]
  int v166; // [rsp+30h] [rbp-100h]
  char v167; // [rsp+30h] [rbp-100h]
  int v168; // [rsp+38h] [rbp-F8h]
  __int64 v169; // [rsp+38h] [rbp-F8h]
  int v171; // [rsp+48h] [rbp-E8h]
  int v172; // [rsp+48h] [rbp-E8h]
  int longind; // [rsp+5Ch] [rbp-D4h] BYREF
  char *v175; // [rsp+60h] [rbp-D0h] BYREF
  char *v176; // [rsp+68h] [rbp-C8h] BYREF
  __m128i v177; // [rsp+70h] [rbp-C0h] BYREF
  char v178[107]; // [rsp+8Dh] [rbp-A3h] BYREF
  unsigned __int64 v179; // [rsp+F8h] [rbp-38h]

  v11 = *a2;
  v179 = __readfsqword(0x28u);
  if ( !v11 )
  {
LABEL_379:
    fwrite("A NULL argv[0] was passed through an exec system call.\n", 1uLL, 0x37uLL, stderr);
    abort();
  }
  v12 = strrchr(v11, 47);
  v13 = v12;
  if ( v12 )
  {
    v14 = v12 + 1;
    if ( v12 + 1 - v11 > 6 && !strncmp(v12 - 6, "/.libs/", 7uLL) )
    {
      v11 = (char *)v14;
      if ( !strncmp(v14, "lt-", 3uLL) )
      {
        v11 = v13 + 4;
        program_invocation_short_name = v13 + 4;
      }
    }
  }
  qword_23460 = (__int64)v11;
  program_invocation_name = v11;
  setlocale(6, "");
  bindtextdomain("coreutils", "/usr/share/locale");
  textdomain("coreutils");
  status = 2;
  sub_18D90((void (*)(void *))sub_B880);
  si128 = (__m128)_mm_load_si128((const __m128i *)&xmmword_1DAF0);
  dword_2372C = 0;
  byte_23728 = 1;
  ptr = 0LL;
  v161 = -1LL;
  v160 = -1LL;
  v168 = -1;
  v166 = -1;
  HIDWORD(v164) = -1;
  v171 = -1;
  BYTE3(v164) = 0;
  s1 = 0LL;
  tp = (struct timespec)si128;
  while ( 1 )
  {
    longind = -1;
    v16 = getopt_long(a1, a2, "abcdfghiklmnopqrstuvw:xABCDFGHI:LNQRST:UXZ1", &longopts, &longind);
    if ( v16 == -1 )
      break;
    switch ( v16 )
    {
      case -131:
        v31 = sub_8C20("David MacKenzie", (__int64)"David MacKenzie");
        v32 = sub_8C20("Richard M. Stallman", (__int64)"Richard M. Stallman");
        sub_11790(
          stdout,
          si128,
          a5,
          a6,
          a7,
          v33,
          v34,
          a10,
          a11,
          (__int64)"ls",
          (__int64)"GNU coreutils",
          (__int64)"9.4",
          (__int64)v32,
          (__int64)v31,
          0);
        exit(0);
      case -130:
        sub_90E0(0);
      case 49:
        v171 = v171 != 0;
        continue;
      case 65:
        dword_2348C = 1;
        continue;
      case 66:
        sub_E470();
        sub_E470();
        continue;
      case 67:
        v171 = 2;
        continue;
      case 68:
        byte_23678 = 1;
        continue;
      case 70:
        if ( !optarg
          || (v30 = dword_197A0[sub_13EC0(
                                  (__int64)"--classify",
                                  optarg,
                                  (const char **)&off_222E0,
                                  (__int64)dword_197A0,
                                  (void (__fastcall *)(struct _IO_FILE *, const char *, char *, __int64, _DWORD *))sub_99E0)],
              v30 == 1)
          || v30 == 2 && (unsigned __int8)sub_9EE0() )
        {
          dword_23334 = 3;
        }
        continue;
      case 71:
        byte_2308C = 0;
        continue;
      case 72:
        dword_2333C = 2;
        continue;
      case 73:
        sub_E470();
        continue;
      case 76:
        dword_2333C = 4;
        continue;
      case 78:
        v166 = 0;
        continue;
      case 81:
        v166 = 5;
        continue;
      case 82:
        byte_23700 = 1;
        continue;
      case 83:
        goto LABEL_73;
      case 84:
        v159 = dcgettext(0LL, "invalid tab size", 5);
        v26 = optarg;
        v27 = sub_11F60((unsigned __int8 *)optarg, 0LL, (unsigned __int64 *)&v177, "");
        switch ( v27 )
        {
          case 0:
            v160 = v177.m128i_i64[0];
            if ( v177.m128i_i64[0] >= 0 )
              continue;
LABEL_69:
            *__errno_location() = 75;
            break;
          case 1:
            goto LABEL_69;
          case 3:
            *__errno_location() = 0;
            break;
        }
        v28 = sub_13CE0(0, (__int64)v26, (__int64)&unk_23040);
        v29 = *__errno_location();
        if ( v29 == 22 )
          v29 = 0;
        error(2, v29, "%s: %s", v159, v28);
LABEL_73:
        v168 = 3;
        break;
      case 85:
        v168 = 6;
        continue;
      case 88:
        v168 = 1;
        continue;
      case 90:
        byte_23333 = 1;
        continue;
      case 97:
        dword_2348C = 2;
        continue;
      case 98:
        v166 = 7;
        continue;
      case 99:
        dword_243E4 = 1;
        continue;
      case 100:
        byte_23338 = 1;
        continue;
      case 102:
        dword_2348C = 2;
        if ( !v171 )
          v171 = -1;
        byte_23342 = 0;
        byte_23330 = 0;
        byte_23348 = 0;
        v168 = 6;
        continue;
      case 103:
        byte_2308D = 0;
        goto LABEL_13;
      case 104:
        dword_232DC = 176;
        dword_232D8 = 176;
        qword_232D0 = 1LL;
        qword_23080 = 1LL;
        continue;
      case 105:
        byte_23349 = 1;
        continue;
      case 107:
        BYTE3(v164) = 1;
        continue;
      case 108:
LABEL_13:
        v171 = 0;
        continue;
      case 109:
        v171 = 4;
        continue;
      case 110:
        byte_232CC = 1;
        v171 = 0;
        continue;
      case 111:
        byte_2308C = 0;
        v171 = 0;
        continue;
      case 112:
        dword_23334 = 1;
        continue;
      case 113:
        HIDWORD(v164) = 1;
        continue;
      case 114:
        byte_23488 = 1;
        continue;
      case 115:
        byte_23348 = 1;
        continue;
      case 116:
        v168 = 5;
        continue;
      case 117:
        dword_243E4 = 2;
        continue;
      case 118:
        goto LABEL_45;
      case 119:
        v161 = sub_9070((__int64)optarg);
        if ( v161 >= 0 )
          continue;
        v24 = (const char *)sub_9CF0((__int64)optarg);
        v25 = dcgettext(0LL, "invalid line width", 5);
        error(2, 0, "%s: %s", v25, v24);
LABEL_45:
        v168 = 4;
        continue;
      case 120:
        v171 = 3;
        continue;
      case 128:
        byte_23343 = 1;
        continue;
      case 129:
        v22 = (char *)&optarg;
        v23 = sub_12420(optarg);
        if ( v23 )
          goto LABEL_367;
        dword_232D8 = dword_232DC;
        qword_23080 = qword_232D0;
        continue;
      case 130:
        if ( !optarg
          || (v20 = dword_197A0[sub_13EC0(
                                  (__int64)"--color",
                                  optarg,
                                  (const char **)&off_222E0,
                                  (__int64)dword_197A0,
                                  (void (__fastcall *)(struct _IO_FILE *, const char *, char *, __int64, _DWORD *))sub_99E0)],
              v20 == 1) )
        {
          v21 = 1;
        }
        else
        {
          v21 = 0;
          if ( v20 == 2 )
            v21 = sub_9EE0();
        }
        byte_23342 = v21 & 1;
        continue;
      case 131:
        dword_2333C = 3;
        continue;
      case 132:
        dword_23334 = 2;
        continue;
      case 133:
        v171 = dword_19720[sub_13EC0(
                             (__int64)"--format",
                             optarg,
                             (const char **)off_22200,
                             (__int64)dword_19720,
                             (void (__fastcall *)(struct _IO_FILE *, const char *, char *, __int64, _DWORD *))sub_99E0)];
        continue;
      case 134:
        v171 = 0;
        s1 = "full-iso";
        continue;
      case 135:
        byte_23701 = 1;
        continue;
      case 136:
        v19 = malloc(0x10uLL);
        if ( !v19 )
          goto LABEL_273;
        si128 = _mm_loadh_ps((const double *)&qword_23480);
        qword_23480 = (__int64)v19;
        *v19 = si128;
        continue;
      case 137:
        if ( !optarg
          || (v17 = dword_197A0[sub_13EC0(
                                  (__int64)"--hyperlink",
                                  optarg,
                                  (const char **)&off_222E0,
                                  (__int64)dword_197A0,
                                  (void (__fastcall *)(struct _IO_FILE *, const char *, char *, __int64, _DWORD *))sub_99E0)],
              v17 == 1) )
        {
          v18 = 1;
        }
        else
        {
          v18 = 0;
          if ( v17 == 2 )
            v18 = sub_9EE0();
        }
        byte_23330 = v18 & 1;
        continue;
      case 138:
        dword_23334 = dword_19710[sub_13EC0(
                                    (__int64)"--indicator-style",
                                    optarg,
                                    (const char **)off_221C0,
                                    (__int64)dword_19710,
                                    (void (__fastcall *)(struct _IO_FILE *, const char *, char *, __int64, _DWORD *))sub_99E0)];
        continue;
      case 139:
        v166 = dword_196E0[sub_13EC0(
                             (__int64)"--quoting-style",
                             optarg,
                             (const char **)off_229C0,
                             (__int64)dword_196E0,
                             (void (__fastcall *)(struct _IO_FILE *, const char *, char *, __int64, _DWORD *))sub_99E0)];
        continue;
      case 140:
        goto LABEL_9;
      case 141:
        dword_232DC = 144;
        dword_232D8 = 144;
        qword_232D0 = 1LL;
        qword_23080 = 1LL;
        continue;
      case 142:
        v168 = dword_19770[sub_13EC0(
                             (__int64)"--sort",
                             optarg,
                             (const char **)&off_222A0,
                             (__int64)dword_19770,
                             (void (__fastcall *)(struct _IO_FILE *, const char *, char *, __int64, _DWORD *))sub_99E0)];
        continue;
      case 143:
        dword_243E4 = dword_19740[sub_13EC0(
                                    (__int64)"--time",
                                    optarg,
                                    (const char **)&off_22240,
                                    (__int64)dword_19740,
                                    (void (__fastcall *)(struct _IO_FILE *, const char *, char *, __int64, _DWORD *))sub_99E0)];
        continue;
      case 144:
        s1 = optarg;
        continue;
      case 145:
        byte_23078 = 0;
        byte_23342 = 0;
        v171 = v171 != 0;
        v166 = 0;
LABEL_9:
        HIDWORD(v164) = 0;
        continue;
      default:
        goto LABEL_336;
    }
  }
  if ( !qword_232D0 )
  {
    v94 = getenv("LS_BLOCK_SIZE");
    sub_12420(v94);
    if ( v94 || getenv("BLOCK_SIZE") )
    {
      dword_232D8 = dword_232DC;
      qword_23080 = qword_232D0;
    }
    if ( BYTE3(v164) )
    {
      qword_232D0 = 1024LL;
      dword_232DC = 0;
    }
  }
  v35 = v171;
  if ( v171 < 0 )
    v35 = (unsigned __int8)sub_9EE0() + 1;
  dword_23344 = v35;
  if ( (unsigned int)(v35 - 2) <= 2 || byte_23342 )
  {
    if ( v161 >= 0 )
    {
LABEL_98:
      v36 = v161;
      goto LABEL_99;
    }
    if ( (unsigned __int8)sub_9EE0() && ioctl(1, 0x5413uLL, &v177) >= 0 && v177.m128i_i16[1] )
    {
      v161 = v177.m128i_u16[1];
      goto LABEL_98;
    }
    v126 = getenv("COLUMNS");
    v127 = (__int64)v126;
    if ( v126 && *v126 )
    {
      v161 = sub_9070((__int64)v126);
      if ( v161 >= 0 )
        goto LABEL_98;
      v143 = sub_9CF0(v127);
      v144 = dcgettext(0LL, "ignoring invalid width in environment variable COLUMNS: %s", 5);
      error(0, 0, v144, v143);
    }
  }
  else if ( v161 >= 0 )
  {
    goto LABEL_98;
  }
  v36 = 80LL;
LABEL_99:
  qword_23478 = v36;
  qword_23470 = v36 / 3 - ((v36 % 3 == 0) - 1LL);
  if ( (unsigned int)(dword_23344 - 2) > 2 )
    goto LABEL_102;
  v37 = v160;
  if ( v160 >= 0 )
    goto LABEL_101;
  qword_23708 = 8LL;
  v67 = (unsigned __int8 *)getenv("TABSIZE");
  v68 = (__int64)v67;
  if ( v67 )
  {
    if ( !(unsigned int)sub_11F60(v67, 0LL, (unsigned __int64 *)&v177, "") )
    {
      v37 = v177.m128i_i64[0];
LABEL_101:
      qword_23708 = v37;
      goto LABEL_102;
    }
    v155 = sub_9CF0(v68);
    v156 = dcgettext(0LL, "ignoring invalid tab size in environment variable TABSIZE: %s", 5);
    error(0, 0, v156, v155);
  }
LABEL_102:
  if ( v164 < 0 )
    v38 = sub_9EE0();
  else
    v38 = HIDWORD(v164) != 0;
  byte_232CB = v38;
  if ( v166 >= 0 )
    goto LABEL_105;
  v80 = getenv("QUOTING_STYLE");
  v81 = (__int64)v80;
  if ( v80 )
  {
    v82 = sub_11E70(v80, (const char **)off_229C0, (__int64)dword_196E0);
    if ( v82 < 0 )
    {
      v145 = sub_9CF0(v81);
      v146 = dcgettext(0LL, "ignoring invalid value of environment variable QUOTING_STYLE: %s", 5);
      error(0, 0, v146, v145);
    }
    else
    {
      v166 = dword_196E0[v82];
      if ( v166 >= 0 )
      {
LABEL_105:
        LODWORD(xmmword_232E0) = v166;
        goto LABEL_106;
      }
    }
  }
  if ( (unsigned __int8)sub_9EE0() )
  {
    v166 = 3;
    goto LABEL_105;
  }
LABEL_106:
  v39 = dword_23344;
  v40 = xmmword_232E0;
  if ( dword_23344 && ((unsigned int)(dword_23344 - 2) > 1 || !qword_23478) || (unsigned int)xmmword_232E0 > 6 )
  {
    byte_232CA = 0;
    v41 = sub_11E10();
    qword_235A0 = (__int64)v41;
    if ( v40 == 7 )
      v41->m128i_i32[3] |= 1u;
  }
  else
  {
    v66 = 74LL;
    if ( _bittest64(&v66, (unsigned int)xmmword_232E0) )
      byte_232CA = 1;
    else
      byte_232CA = 0;
    v41 = sub_11E10();
    qword_235A0 = (__int64)v41;
  }
  if ( (unsigned int)dword_23334 > 1 )
  {
    v42 = &asc_1B116[dword_23334 - 2];
    v43 = *v42;
    if ( *v42 )
    {
      v44 = &v41->m128i_i64[1];
      do
      {
        v45 = (int *)v44 + (v43 >> 5);
        v46 = *v45;
        ++v42;
        v47 = !_bittest(&v46, v43 & 0x1F) << (v43 & 0x1F);
        v43 = *v42;
        *v45 ^= v47;
      }
      while ( v43 );
    }
  }
  v48 = sub_11E10();
  v49 = v48->m128i_i32[3];
  qword_23468 = (__int64)v48;
  v48->m128i_i32[3] = v49 ^ ~v49 & 0x4000000;
  byte_23678 &= (v39 == 0) & (byte_23330 ^ 1);
  if ( byte_23078 < (int)(unsigned __int8)byte_23678 )
  {
    v157 = dcgettext(0LL, "--dired and --zero are incompatible", 5);
    error(2, 0, v157);
    goto LABEL_379;
  }
  v50 = v168;
  if ( v168 < 0 )
  {
    v50 = 0;
    if ( v39 )
      v50 = (unsigned int)(dword_243E4 - 1) < 3 ? 5 : 0;
  }
  dword_243E0 = v50;
  if ( v39 )
    goto LABEL_122;
  if ( s1 || (s1 = getenv("TIME_STYLE")) != 0LL )
  {
    for ( i = s1; !strncmp(i, "posix-", 6uLL); i += 6 )
    {
      if ( !sub_C6A0(2) )
        goto LABEL_122;
    }
    s1a = (char *)i;
  }
  else
  {
    s1a = (char *)"locale";
  }
  if ( *s1a != 43 )
  {
    v115 = off_22180;
    v116 = (int)s1a;
    v117 = off_22180;
    v118 = sub_11E70(s1a, (const char **)off_22180, (__int64)&unk_196C0);
    if ( v118 < 0 )
    {
      sub_C040((__int64)"time style", (__int64)s1a, v118);
      v136 = stderr;
      v137 = dcgettext(0LL, "Valid arguments are:\n", 5);
      fputs_unlocked(v137, v136);
      while ( 1 )
      {
        v138 = stderr;
        if ( !*v115 )
          break;
        ++v115;
        __fprintf_chk();
      }
      v139 = dcgettext(0LL, "  - +FORMAT (e.g., +%H:%M) for a 'date'-style format\n", 5);
      fputs_unlocked(v139, v138);
LABEL_336:
      sub_90E0(2);
    }
    if ( v118 == 2 )
    {
      v120 = "%Y-%m-%d ";
      a6 = (__m128)(unsigned __int64)"%m-%d %H:%M";
      si128 = (__m128)_mm_unpacklo_epi64(
                        (__m128i)(unsigned __int64)"%Y-%m-%d ",
                        (__m128i)(unsigned __int64)"%m-%d %H:%M");
      *(__m128 *)&off_23240 = si128;
    }
    else if ( v118 > 2 )
    {
      if ( v118 == 3 )
      {
        v116 = 2;
        if ( sub_C6A0(2) )
        {
          v140 = dcgettext(0LL, off_23240, 2);
          LODWORD(v117) = (_DWORD)off_23248;
          v116 = 0;
          off_23240 = v140;
          off_23248 = dcgettext(0LL, off_23248, 2);
        }
      }
    }
    else
    {
      if ( v118 )
        si128 = (__m128)_mm_unpacklo_epi64(
                          (__m128i)(unsigned __int64)"%Y-%m-%d %H:%M",
                          (__m128i)(unsigned __int64)"%Y-%m-%d %H:%M");
      else
        si128 = (__m128)_mm_unpacklo_epi64(
                          (__m128i)(unsigned __int64)"%Y-%m-%d %H:%M:%S.%N %z",
                          (__m128i)(unsigned __int64)"%Y-%m-%d %H:%M:%S.%N %z");
      *(__m128 *)&off_23240 = si128;
    }
    goto LABEL_284;
  }
  LODWORD(v117) = 10;
  v116 = (_DWORD)s1a + 1;
  v141 = strchr(s1a + 1, 10);
  v142 = v141;
  if ( !v141 )
  {
    v22 = s1a + 1;
    goto LABEL_351;
  }
  v22 = v141 + 1;
  LODWORD(v117) = 10;
  v116 = (_DWORD)v141 + 1;
  if ( strchr(v141 + 1, 10) )
  {
    v147 = sub_9CF0((__int64)(s1a + 1));
    v148 = dcgettext(0LL, "invalid time style format %s", 5);
    error(2, 0, v148, v147);
LABEL_367:
    v149 = *(_QWORD *)v22;
    v150 = status;
    if ( v23 > 3 )
    {
      v151 = "invalid %s%s argument '%s'";
      if ( v23 != 4 )
        goto LABEL_373;
    }
    else
    {
      v151 = "invalid suffix in %s%s argument '%s'";
      if ( v23 == 1 )
        v151 = "%s%s argument '%s' too large";
    }
    if ( longind < 0 )
    {
      v153 = &v178[3];
      *(_WORD *)&v178[3] = 0;
      v152 = &asc_1B00E[-longind];
    }
    else
    {
      v152 = "--";
      v153 = (char *)*((_QWORD *)&longopts.name + 4 * longind);
    }
    v154 = dcgettext(0LL, v151, 5);
    error(v150, 0, v154, v152, v153, v149);
LABEL_373:
    abort();
  }
  *v142 = 0;
LABEL_351:
  off_23240 = s1a + 1;
  off_23248 = v22;
LABEL_284:
  sub_8280(v116, (_DWORD)v117, v119, (_DWORD)v120, v121, v122, v158, (__int64)v159, v160, v161, (__int64)s1a, v164);
LABEL_122:
  v172 = optind;
  v165 = byte_23342;
  if ( !byte_23342 )
    goto LABEL_123;
  v95 = getenv("LS_COLORS");
  v175 = v95;
  if ( v95 && *v95 )
  {
    strcpy(v178, "??");
    qword_23498 = (void *)sub_10B30(v95);
    v176 = (char *)qword_23498;
    while ( 1 )
    {
LABEL_247:
      while ( 1 )
      {
        v96 = v175;
        v97 = *v175;
        if ( *v175 != 42 )
          break;
        v134 = malloc(0x30uLL);
        if ( !v134 )
          goto LABEL_273;
        v135 = qword_23490;
        v134[32] = 0;
        *((_QWORD *)v134 + 5) = v135;
        *((_QWORD *)v134 + 1) = v176;
        qword_23490 = (__int64)v134;
        v175 = v96 + 1;
        if ( (unsigned __int8)sub_6EA0(&v176, &v175, 1u, v134) )
        {
          v106 = *v175++ == 61;
          if ( v106 )
          {
            *((_QWORD *)v134 + 3) = v176;
            if ( (unsigned __int8)sub_6EA0(&v176, &v175, 0, (_QWORD *)v134 + 2) )
              continue;
          }
        }
        goto LABEL_271;
      }
      if ( v97 != 58 )
        break;
      ++v175;
    }
    if ( v97 )
    {
      v178[0] = *v175;
      v105 = *++v175;
      if ( v105 )
      {
        v178[1] = v105;
        v106 = v96[2] == 61;
        v175 = v96 + 3;
        if ( v106 )
        {
          v107 = 0LL;
          v108 = "lc";
          while ( strcmp(v178, v108) )
          {
            v108 = off_228E0[++v107];
            if ( !v108 )
              goto LABEL_270;
          }
          v109 = &qword_230C0[2 * (int)v107];
          v109[1] = (__int64)v176;
          if ( (unsigned __int8)sub_6EA0(&v176, &v175, 0, v109) )
            goto LABEL_247;
LABEL_270:
          v110 = sub_9CF0((__int64)v178);
          v111 = dcgettext(0LL, "unrecognized prefix: %s", 5);
          error(0, 0, v111, v110);
        }
      }
LABEL_271:
      v112 = dcgettext(0LL, "unparsable value for LS_COLORS environment variable", 5);
      error(0, 0, v112);
      free(qword_23498);
      for ( j = (_QWORD *)qword_23490; j; j = v133 )
      {
        v133 = (_QWORD *)j[5];
        free(j);
      }
      byte_23342 = 0;
      goto LABEL_322;
    }
    v98 = qword_23490;
    if ( qword_23490 )
    {
      while ( 1 )
      {
        v99 = v98;
        v100 = *(_QWORD *)(v98 + 40);
        if ( !v100 )
          break;
        v167 = 0;
        v101 = v100;
        v169 = v100;
        do
        {
          v102 = *(_QWORD *)v101;
          if ( *(_QWORD *)v101 != -1LL && v102 == *(_QWORD *)v99 )
          {
            v103 = *(const void **)(v101 + 8);
            v104 = *(const void **)(v99 + 8);
            if ( !memcmp(v104, v103, *(_QWORD *)v101) )
            {
              *(_QWORD *)v101 = -1LL;
            }
            else if ( v103 == v104 || !v102 || !(unsigned int)sub_7D70((__int64)v104, (__int64)v103, v102) )
            {
              if ( v167
                || (v114 = *(_QWORD *)(v99 + 16), v114 == *(_QWORD *)(v101 + 16))
                && !memcmp(*(const void **)(v99 + 24), *(const void **)(v101 + 24), v114) )
              {
                *(_QWORD *)v101 = -1LL;
                v167 = v165;
              }
              else
              {
                *(_BYTE *)(v99 + 32) = 1;
                *(_BYTE *)(v101 + 32) = 1;
              }
            }
          }
          v101 = *(_QWORD *)(v101 + 40);
        }
        while ( v101 );
        v98 = v169;
      }
    }
LABEL_322:
    if ( qword_23130 == 6 && !strncmp(off_23138, "target", 6uLL) )
      byte_23340 = 1;
  }
  else
  {
    v128 = getenv("COLORTERM");
    if ( !v128 || !*v128 )
    {
      v129 = getenv("TERM");
      v130 = v129;
      if ( v129 && *v129 )
      {
        for ( k = "# Configuration file for dircolors, a utility to help you set the";
              (unsigned __int64)(k - "# Configuration file for dircolors, a utility to help you set the") <= 0x1568;
              k += strlen(k) + 1 )
        {
          if ( !strncmp(k, "TERM ", 5uLL) && !fnmatch(k + 5, v130, 0) )
            goto LABEL_309;
        }
      }
      byte_23342 = 0;
    }
  }
LABEL_309:
  if ( !byte_23342 )
  {
LABEL_123:
    if ( !byte_23701 )
      goto LABEL_125;
    goto LABEL_124;
  }
  qword_23708 = 0LL;
  if ( byte_23701
    || (unsigned __int8)sub_BBB0(0xDu)
    || (unsigned __int8)sub_BBB0(0xEu) && byte_23340
    || (unsigned __int8)sub_BBB0(0xCu) && !dword_23344 )
  {
LABEL_124:
    byte_23341 = 1;
  }
LABEL_125:
  if ( !dword_2333C )
  {
    v52 = 1;
    if ( !byte_23338 && dword_23334 != 3 )
      v52 = dword_23344 == 0 ? 1 : 3;
    dword_2333C = v52;
  }
  if ( byte_23700 )
  {
    qword_236F8 = sub_16A40(0x1EuLL, (__int64)sub_6E20, (__int64)sub_6E30, (__int64)j_free);
    if ( !qword_236F8 )
      goto LABEL_273;
    obstack_begin(&xmmword_236A0, 0LL, 0LL, (__int64)&malloc, (__int64)&free);
  }
  v53 = getenv("TZ");
  qword_23680 = (__int64)sub_8FC0(v53);
  if ( ((dword_243E0 - 3) & 0xFFFFFFFD) == 0 || !dword_23344 || byte_23333 || byte_23348 )
  {
    byte_23332 = 1;
    v54 = 0;
  }
  else
  {
    byte_23332 = 0;
    v54 = 1;
    if ( !byte_23700 && !byte_23342 && !dword_23334 )
      v54 = byte_23701;
  }
  byte_23331 = v54 & 1;
  if ( byte_23678 )
  {
    obstack_begin(xmmword_23620, 0LL, 0LL, (__int64)&malloc, (__int64)&free);
    obstack_begin(xmmword_235C0, 0LL, 0LL, (__int64)&malloc, (__int64)&free);
  }
  if ( byte_23330 )
  {
    v83 = 0LL;
    while ( 1 )
    {
      v84 = v83;
      if ( v83 > 0x5A )
        break;
      while ( 1 )
      {
        if ( v83 > 0x40 || (unsigned int)(v84 - 48) <= 9 )
          goto LABEL_235;
LABEL_225:
        if ( (_DWORD)v83 != 126 && (_DWORD)v83 != 45 )
          break;
LABEL_235:
        byte_234A0[v83++] |= 1u;
        v84 = v83;
        if ( v83 > 0x5A )
          goto LABEL_236;
      }
      v85 = (_DWORD)v83 == 95 || (_DWORD)v83 == 46;
LABEL_228:
      byte_234A0[v83++] |= v85;
      if ( v83 == 256 )
      {
        v177.m128i_i64[0] = 100LL;
        v86 = 0LL;
        v87 = &v178[3];
        v88 = 0xFFFFFFEFFFBFEFFELL;
        v89 = __errno_location();
        while ( 1 )
        {
          v90 = v177.m128i_i64[0];
          v87[v177.m128i_i64[0] - 1] = 0;
          v91 = v90 - 1;
          *v89 = 0;
          if ( !gethostname(v87, v90 - 1) )
          {
            v92 = strlen(v87);
            if ( v91 > (__int64)(v92 + 1) )
            {
              if ( v86 )
              {
                qword_235A8 = (__int64)v86;
                goto LABEL_137;
              }
              if ( malloc(v92 + 1) )
              {
                qword_235A8 = __memcpy_chk();
                goto LABEL_137;
              }
LABEL_273:
              sub_E430();
            }
            *v89 = 0;
          }
          free(v86);
          v93 = (unsigned int)*v89;
          if ( (unsigned int)v93 > 0x24 || _bittest64((const __int64 *)&v88, v93) )
          {
            qword_235A8 = (__int64)"";
            goto LABEL_137;
          }
          v86 = sub_10A20(0LL, v177.m128i_i64, 1LL, -1LL, 1LL);
          v87 = (char *)v86;
        }
      }
    }
LABEL_236:
    v85 = 1;
    if ( (unsigned int)(v83 - 97) <= 0x19 )
      goto LABEL_228;
    goto LABEL_225;
  }
LABEL_137:
  qword_23328 = 100LL;
  v55 = reallocarray();
  if ( !v55 )
    goto LABEL_273;
  qword_23320 = v55;
  qword_23318 = 0LL;
  sub_9F10();
  if ( a1 - v172 <= 0 )
  {
    if ( byte_23338 )
    {
      v58 = 3LL;
      v57 = ".";
      sub_17490(".", 3u, (_BYTE *)&dword_0 + 1, "");
    }
    else
    {
      v58 = 0LL;
      v57 = ".";
      sub_10B70(".", 0LL, 1);
    }
    v59 = ptr;
    if ( !qword_23318 )
      goto LABEL_181;
    goto LABEL_285;
  }
  v56 = v172;
  do
  {
    v57 = a2[v56];
    v58 = 0LL;
    ++v56;
    sub_17490(v57, 0, (_BYTE *)&dword_0 + 1, "");
  }
  while ( a1 > (int)v56 );
  if ( qword_23318 )
  {
LABEL_285:
    sub_E4B0(*(double *)si128.m128_u64, a5, a6);
    if ( !byte_23338 )
    {
      v58 = 1LL;
      v57 = 0LL;
      sub_10BF0(0LL, 1);
    }
    if ( qword_23318 )
    {
      sub_105E0((__int64)v57, v58, v123, v124);
      if ( !ptr )
        goto LABEL_152;
      ++qword_23350;
      IO_write_ptr = stdout->_IO_write_ptr;
      if ( IO_write_ptr < stdout->_IO_write_end )
      {
        v59 = ptr;
        stdout->_IO_write_ptr = IO_write_ptr + 1;
        *IO_write_ptr = 10;
        goto LABEL_146;
      }
      __overflow(stdout, 10);
      v59 = ptr;
      goto LABEL_143;
    }
  }
  v59 = ptr;
  if ( a1 - v172 > 1 )
  {
LABEL_143:
    if ( v59 )
      goto LABEL_146;
    goto LABEL_152;
  }
LABEL_181:
  if ( v59 )
  {
    if ( !*((_QWORD *)v59 + 3) )
      byte_23728 = 0;
    do
    {
LABEL_146:
      while ( 1 )
      {
        v60 = (unsigned int **)qword_236F8;
        v61 = *(char **)v59;
        ptr = (void *)*((_QWORD *)v59 + 3);
        if ( qword_236F8 )
        {
          if ( !v61 )
            break;
        }
        sub_10FC0(v61, *((_QWORD *)v59 + 1), *((_BYTE *)v59 + 16), (__m128i)si128, a5, a6);
        free(*(void **)v59);
        free(*((void **)v59 + 1));
        free(v59);
        v59 = ptr;
        byte_23728 = 1;
        if ( !ptr )
          goto LABEL_152;
      }
      if ( (unsigned __int64)(qword_236B8 - qword_236B0) <= 0xF )
        __assert_fail(
          "dev_ino_size <= __extension__ ({ struct obstack const *__o = (&dev_ino_obstack); (size_t) (__o->next_free - __"
          "o->object_base); })",
          "src/ls.c",
          0x41Du,
          "dev_ino_pop");
      a5 = (__m128)_mm_loadu_si128((const __m128i *)(qword_236B8 - 16));
      qword_236B8 -= 16LL;
      v177 = (__m128i)a5;
      v62 = (void *)sub_9A50((__int64)qword_236F8, (__int64)&v177, (__m128i **)&v176, 1);
      if ( !v62 )
        __assert_fail("found", "src/ls.c", 0x70Cu, "main");
      v63 = v176;
      v60[4] = (unsigned int *)((char *)v60[4] - 1);
      if ( !*(_QWORD *)v63 )
      {
        v69 = (__int64)v60[3] - 1;
        v60[3] = (unsigned int *)v69;
        v70 = v69 < 0
            ? (float)(v69 & 1 | (unsigned int)((unsigned __int64)v69 >> 1))
            + (float)(v69 & 1 | (unsigned int)((unsigned __int64)v69 >> 1))
            : (float)(int)v69;
        v71 = (__int64)v60[2];
        if ( v71 < 0 )
        {
          v132 = (unsigned __int64)v60[2] & 1 | ((unsigned __int64)v60[2] >> 1);
          v72 = (float)(int)v132 + (float)(int)v132;
        }
        else
        {
          v72 = (float)(int)v71;
        }
        si128 = (__m128)*v60[5];
        si128.m128_f32[0] = si128.m128_f32[0] * v72;
        if ( si128.m128_f32[0] > v70 )
        {
          sub_C7B0((__int64)v60);
          v74 = (float *)v60[5];
          si128 = (__m128)*(unsigned int *)v74;
          si128.m128_f32[0] = si128.m128_f32[0] * v73;
          if ( si128.m128_f32[0] > v75 )
          {
            v76 = v73 * v74[1];
            if ( !*((_BYTE *)v74 + 16) )
              v76 = v76 * v74[2];
            if ( v76 >= 9.223372e18 )
              v77 = (unsigned int)(int)(float)(v76 - 9.223372e18) ^ 0x8000000000000000LL;
            else
              v77 = (unsigned int)(int)v76;
            if ( !(unsigned __int8)sub_B590((__int64)v60, v77) )
            {
              for ( m = v60[9]; m; m = v79 )
              {
                v79 = (unsigned int *)*((_QWORD *)m + 1);
                free(m);
              }
              v60[9] = 0LL;
            }
          }
        }
      }
      free(v62);
      free(*(void **)v59);
      free(*((void **)v59 + 1));
      free(v59);
      v59 = ptr;
    }
    while ( ptr );
  }
LABEL_152:
  if ( byte_23342 && byte_237C0 )
  {
    if ( qword_230C0[0] != 2 || *(_WORD *)off_230C8 != 23323 || qword_230D0 != 1 || *(_BYTE *)off_230D8 != 109 )
    {
      sub_BE90((__int64)qword_230C0);
      sub_BE90((__int64)&qword_230D0);
    }
    fflush_unlocked(stdout);
    sub_8A60(0);
    for ( n = dword_237C4; n; --n )
      raise(19);
    if ( sig )
      raise(sig);
  }
  if ( byte_23678 )
  {
    sub_8190("//DIRED//", (__int64)xmmword_23620);
    sub_8190("//SUBDIRED//", (__int64)xmmword_235C0);
    __printf_chk();
  }
  if ( qword_236F8 )
  {
    if ( *((_QWORD *)qword_236F8 + 4) )
      __assert_fail("hash_get_n_entries (active_dir_set) == 0", "src/ls.c", 0x740u, "main");
    sub_C840((unsigned __int64 *)qword_236F8);
  }
  return (unsigned int)dword_2372C;
}
